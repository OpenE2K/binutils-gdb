/* C language support routines for GDB, the GNU debugger with E2K
   specifics for manipulating (printing) registers' values.

   Copyright (C) 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000, 2002, 2003,
   2004, 2005, 2007, 2008, 2009, 2010 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "defs.h"
#include "symtab.h"
#include "expression.h"
#include "parser-defs.h"
#include "language.h"
#include "varobj.h"
#include "c-lang.h"
#include "valprint.h"
#include "gdbarch.h"
#include "e2k-tdep.h"
#include "target-descriptions.h"

#include <string.h>


static void
print_tags (struct ui_file *stream, struct type *etags_type,
	    const gdb_byte *etags, int frst_fld, int last_fld)
{
  int i;
  fputs_filtered ("<", stream);

  for (i = last_fld; i >= frst_fld; i--)
    {
      int tag = unpack_field_as_long  (etags_type, etags, i);
      if (tag == 1)
	{
	  ui_file_style style = { ui_file_style::RED, ui_file_style::NONE,
				  ui_file_style::BOLD };
	  fprintf_styled (stream, style, "%d", tag);
	}
      else
	fprintf_filtered (stream, "%d", tag);
    }

  fputs_filtered ("> ", stream);
}

/* FIXME: what role does "need64" actually play here?  */
static void
print_32_64_bit_value (int need64,
                       struct ui_file *stream,
                       int recurse,
                       struct value *v,
                       const struct value_print_options *options,
                       const struct value_print_options *options_2)
{
  /* Memory contents printed by `x'-command should be zero
     extended to 2, 4, 8 or 16 hexademical digits depending
     on the format in order to obtain accurate columns. As
     far as I understand the `x'-command always sets the
     `format' field in `struct value_print_options' to the
     user specified value or to 'x' by default. When printing
     a tagged register value this field may very well remain
     uninitialized (== 0). I believe that in this case it's
     printed according to the `output-radix' (see also the
     end of `print_formatted').

     However, it's not secure to determine whether we are
     printing a register or memory contents by means of
     format field of `struct value_print_options' since
     the user may very well say `p/x $r7'. In the latter
     case the register value will be zero-extended quite
     unexpectedly. Probably I should introduce different
     types for tagged register values and memory contents.

     There is also another problem: when printing memory
     contents in decimal format, say `x/8dw' different
     raws of the same column may very well have different
     width . . . */

  if (options_2 == NULL && options->format)
    print_scalar_formatted (value_contents (v),
			    check_typedef (value_type (v)),
			    options,
			    need64 ? 'g' : 'w',
			    stream);
  else
    common_val_print (v, stream, recurse + 1, options, current_language);

  if (options_2 != NULL)
    {
      fprintf_filtered (stream, "\t");
      common_val_print (v, stream, recurse + 1, options_2, current_language);
      fprintf_filtered (stream, "\n");
    }
}

static void
print_32_64_bit_tagged_value (int need64,
			      struct type *type,
			      const gdb_byte *vaddr,
			      CORE_ADDR address,
			      struct ui_file *stream,
			      int recurse,
			      const struct value *original_value,
			      const struct value_print_options *options,
                              const struct value_print_options *options_2)
{
  int etags_fld = 1;
  struct type *etags_type = TYPE_FIELD_TYPE (type, etags_fld);
  int etags_offset = TYPE_FIELD_BITPOS (type, etags_fld) / 8;
  const gdb_byte *etags = vaddr + etags_offset;
  struct value *v = value_from_longest (TYPE_FIELD_TYPE (type, 0),
					unpack_field_as_long (type, vaddr, 0));

  print_tags (stream, etags_type, etags, 0, 1);
  print_32_64_bit_value (need64, stream, recurse, v, options, options_2);
}

static void
print_80_bit_tagged_value (struct type *type,
                           const gdb_byte *vaddr,
			   CORE_ADDR address,
                           struct ui_file *stream,
			   int recurse,
                           const struct value *original_value,
                           const struct value_print_options *options,
                           int info_mode)
{
  int j;
  struct value_print_options local_opts = *options;
  int etags_fld = 2;
  struct type *etags_type = TYPE_FIELD_TYPE (type, etags_fld);
  int etags_offset = TYPE_FIELD_BITPOS (type, etags_fld) / 8;
  const gdb_byte *etags = vaddr + etags_offset;
  struct gdbarch *gdbarch = get_type_arch (type);
  struct type *long_double_type = builtin_type (gdbarch)->builtin_long_double;

  print_tags (stream, etags_type, etags, 0, 1);

  /* For the sake of `e2k_print_register_info ()' where one has no
     ORIGINAL_VALUE.  */
  if (original_value == NULL)
    original_value = value_from_contents (long_double_type, vaddr);

  /* This is very special since output radix doesn't
     affect the output format (I don't have any wish
     to print 80-bit decimals anyway . . .). */

  val_print (long_double_type,
             0,
             /* Presumably I can put ADDRESS here, but does this make any sense? */
             address,
             stream, 0,
             /* I have ORIGINAL_VALUE, but is it appropriate here? I can't use
                just NULL here anymore because of the changes that have happened
                somewhere between gdb-7.2 and gdb-7.3.1 (see Bug #58506). The
                `VAL' parameter of `val_print ()' has the meaning of the "whole
                object". From this point of view `ORIGINAL_VALUE' seems to be
                OK. There is another aspect though: this object is expected to
                come from ADDRESS which is not the case, since the tags aren't
                actually stored at dedicated bits in inferior's memory. However,
                when printing the contents of the leading 80 bits this doesn't
                seem crucial, does it?  */
             (struct value *) original_value,
             &local_opts, current_language);

  fprintf_filtered (stream, "\t(raw 0x");
  for (j = 0; j < 10; j++)
    {
      int idx;
      
      idx = 10 - 1 - j;
      fprintf_filtered (stream, "%02x", (unsigned char) vaddr[idx]);
    }
  fprintf_filtered (stream, ")");

  if (info_mode)
    fprintf_filtered (stream, "\n");
}

static void
print_128_bit_tagged_value (struct type *type,
			    const gdb_byte *vaddr,
			    CORE_ADDR address,
			    struct ui_file *stream,
			    int recurse,
			    const struct value *original_value,
			    const struct value_print_options *options,
                            const struct value_print_options *options_2)
{
  int i;
  int etags_fld = 2;
  struct type *etags_type = TYPE_FIELD_TYPE (type, etags_fld);
  int etags_offset = TYPE_FIELD_BITPOS (type, etags_fld) / 8;
  const gdb_byte *etags = vaddr + etags_offset;
  struct value *v;

  for (i = 0; i < 2; i++)
    {
      /* Output `qprX.d<I>'.  */
      v = value_from_longest (TYPE_FIELD_TYPE (type, i),
                              unpack_field_as_long (type, vaddr, i));

      print_tags (stream, etags_type, etags, 2 * i, 2 * i + 1);
      print_32_64_bit_value (1, stream, recurse, v, options, options_2);

      if (i == 0)
        {
          if (options_2 == NULL)
            {
              /* When `print'ing `$qprX' its least and most significant parts
                 are put on the same line and separated with a TAB.  */
              fprintf_filtered (stream, "\t");
            }
          else
            {
              /* In info mode a two column output is used for each half of
                 `$qprX', thus the most significant one is printed on a separate
                 line (`print_32_64_bit_value ()' is responsible for printing
                 `\n' in this case). Ensure that it has the same indentation as
                 the least significant one.  */
              print_spaces_filtered (30, stream);
            }
        }
    }

  /* In info mode it makes sense to separate `$qprX' registers with an extra
     newline because of their "two-line" representation.  */
  if (options_2 != NULL)
    fprintf_filtered (stream, "\n");
}

/* Print data of type TYPE located at VALADDR (within GDB), which came from
   the inferior at address ADDRESS, onto stdio stream STREAM according to
   OPTIONS.  The data at VALADDR is in target byte order.

   If the data are a string pointer, returns the number of string characters
   printed.  */

void
c_e2k_val_print_ex (struct type *type, const gdb_byte *valaddr,
                    int embedded_offset, CORE_ADDR address,
                    struct ui_file *stream, int recurse,
                    struct value *original_value,
                    const struct value_print_options *options,
                    const struct value_print_options *options_2,
                    int mlt_i)
{
  struct gdbarch *gdbarch;

  if ((gdbarch = get_type_arch (type)))
    {
      struct e2k_gdbarch_data *data;

      /* As an example, unavailable window registers are treated as unavailable
         values now.  */
      if (original_value
          && !value_entirely_available ((struct value *) original_value))
        {
          val_print_unavailable (stream);
          return;
        }

      data = get_e2k_gdbarch_data (gdbarch);

      if (type == data->mlt_type)
        {
          int i;
          for (i = 0; i < 3; i++)
            {
              struct type *mlt_t = TYPE_FIELD_TYPE (type, i);
              c_e2k_val_print_ex (mlt_t, valaddr + 8 * i, embedded_offset,
                                  address + 8 * i, stream, recurse,
                                  original_value, options, options_2, i + 1);
            }

          return;
        }

      /* FIXME: if gdbarch may turn out to be different from "e2k_gdbarch"
         (how can I check this?) then the next condition is illegal. */

      /* Treat tagged values specially. */
      if (type == data->tagged32_type
	  || type == data->signed_tagged32_type)
	return print_32_64_bit_tagged_value (0, type, valaddr + embedded_offset,
                                             address, stream, recurse,
                                             original_value, options,
                                             options_2);
      else if (type == data->tagged64_type
	       || type == data->signed_tagged64_type)
	return print_32_64_bit_tagged_value (1, type, valaddr + embedded_offset,
                                             address, stream, recurse,
                                             original_value, options,
                                             options_2);
      else if (type == data->tagged80_type)
	return print_80_bit_tagged_value (type, valaddr + embedded_offset,
                                          address, stream, recurse,
                                          original_value, options,
                                          options_2 != NULL);
      else if (type == data->tagged128_type)
	return print_128_bit_tagged_value (type, valaddr + embedded_offset,
                                           address, stream, recurse,
                                           original_value, options, options_2);
      else if (type == data->pred_type)
        {
          type = TYPE_FIELD_TYPE (type, 1);

          fprintf_filtered
            (stream, "<%d> %d\n",
             (int) unpack_field_as_long (type, valaddr + embedded_offset, 1),
             (int) unpack_field_as_long (type, valaddr + embedded_offset, 0));

          return;
        }
      else if (/* This parameter lets me avoid the need for 'subMLT_{0,1,2}'
                  fake registers which would be required otherwise in order to
                  find related types. FIXME: probably it would be better to get
                  rid of it . . .  */
               mlt_i
               || (TYPE_NAME (type)
                   && tdesc_find_type (gdbarch, TYPE_NAME (type)) == type))
        {
          int i, len;
          struct value *v;
          struct value_print_options hex_opts;
          int info_mode = options_2 != NULL;

          /* "Struct-like" registers are printed in a two-column mode even via
             `print' command. In such a case the first column is printed in hex
             format, while the second in a user-specified one.  */
          if (! info_mode)
            {
              options_2 = options;
              get_formatted_print_options (&hex_opts, 'x');
              options = &hex_opts;
            }
          
          /* Assert that the type is a union with two fields and so on. */
          v = value_from_longest
            (TYPE_FIELD_TYPE (type, 0), 
             unpack_field_as_long (type, valaddr + embedded_offset, 0));

          if (mlt_i != 0)
            {
              fputs_filtered ("\n", stream);
              print_spaces_filtered (35, stream);
            }
          else if (info_mode)
            print_spaces_filtered (5, stream);

          common_val_print (v, stream, recurse, options, current_language);
          fprintf_filtered (stream, "\t");
          common_val_print (v, stream, recurse, options_2, current_language);

          type = TYPE_FIELD_TYPE (type, 1);
          len = TYPE_NFIELDS (type);

          for (i = 0; i < len; i++)
            {
              size_t name_len = strlen (TYPE_FIELD_NAME (type, i));
              /* Don't print empty fields (holes). */
              if (name_len == 0)
                continue;

              fputs_filtered ("\n", stream);

              if (info_mode || mlt_i != 0)
                print_spaces_filtered (4, stream);
                
              fputs_filtered (TYPE_FIELD_NAME (type, i), stream);
              print_spaces_filtered (31 - name_len, stream);

              v = value_from_longest
                (TYPE_FIELD_TYPE (type, i), 
                 unpack_field_as_long (type, valaddr + embedded_offset, i));

              common_val_print (v, stream, recurse + 1, options,
                                current_language);

              fprintf_filtered (stream, "\t");

              common_val_print (v, stream, recurse + 1, options_2,
                                current_language);
            }

          if (info_mode || mlt_i == 1 || mlt_i == 2)
            fprintf_filtered (stream, "\n\n");

          gdb_flush (stream);
          return;
        }
    }

  if (options_2 != NULL)
    {
      struct value *v =
        value_from_longest (type,
                            unpack_long (type, valaddr + embedded_offset));

      /* FIXME: determine whether you actually "need64" here or not.  */
      print_32_64_bit_value (1, stream, recurse, v, options, options_2);
    }
  else
    c_val_print (type, embedded_offset, address,
                 stream, recurse, (struct value *) original_value, options);
}

static void
c_e2k_val_print (struct type *type,
                 int embedded_offset, CORE_ADDR address,
                 struct ui_file *stream, int recurse,
                 struct value *original_value,
                 const struct value_print_options *options)
{
  const gdb_byte *valaddr = value_contents_for_printing (original_value);
  c_e2k_val_print_ex (type, valaddr, embedded_offset, address, stream, recurse,
                      original_value, options, NULL, 0);
}

static struct value *
evaluate_subexp_c_e2k (struct type *expect_type, struct expression *exp,
                       int *pos, enum noside noside)
{
  if (exp->elts[*pos].opcode == BINOP_ASSIGN)
    {
      struct value *arg1, *arg2;
      struct type *type1, *type2;
      struct gdbarch *gdbarch;

      ++*pos;
      arg1 = evaluate_subexp (NULL_TYPE, exp, pos, noside);
      arg2 = evaluate_subexp (value_type (arg1), exp, pos, noside);
      type1 = value_type (arg1);
      type2 = value_type (arg2);

      if ((TYPE_CODE (type2) == TYPE_CODE_INT)
          && (gdbarch = get_type_arch (type1))
          && (type1 == get_e2k_gdbarch_data (gdbarch)->tagged64_type))
        {
          /* Treat a special case of assigning an integer to a
             tagged register value. */

             /* Probably I can do without `temp'. I don't
             understand what `value_struct_elt' needs
             `struct value **' for. */

             struct value *temp = arg1;
             arg1 = value_struct_elt
               (&temp, NULL, "dword", NULL, "structure");
        }

      /* This code is borrowed from `evaluate_subexp_standard' in
         eval.c. It would be attractive to implement assignments
         of register values via some user defined `=' instead of
         this idiocy, however at present `=' cannot be overloaded
         and this functionality applies to C++ (see valarith.c). */

      if (noside == EVAL_SKIP || noside == EVAL_AVOID_SIDE_EFFECTS)
	return arg1;
      if (binop_user_defined_p (BINOP_ASSIGN, &arg1, &arg2))
	return value_x_binop (arg1, arg2, BINOP_ASSIGN, OP_NULL, noside);
      else
	return value_assign (arg1, arg2);

    }

  /* `evaluate_subexp_c' is called this way because it's
     declared static. */
  return exp_descriptor_c.evaluate_exp (expect_type, exp, pos, noside);
}


/* FIXME: this declaration is required here because it's not
   provided by `c-lang.h'. */
extern const struct op_print c_op_print_tab[];


static const struct exp_descriptor exp_descriptor_c_e2k = 
{
  print_subexp_standard,
  operator_length_standard,
  operator_check_standard,
  op_name_standard,
  dump_subexp_body_standard,
  evaluate_subexp_c_e2k
};

#if 1
const struct language_defn c_e2k_language_defn =
{
  "c",				/* Language name */
  "C",
  language_c,
  range_check_off,
  case_sensitive_on,
  array_row_major,
  macro_expansion_c,
  c_extensions,
  &exp_descriptor_c_e2k,
  c_parse,
  null_post_parser,
  c_printchar,			/* Print a character constant */
  c_printstr,			/* Function to print string constant */
  c_emit_char,			/* Print a single char */
  c_print_type,			/* Print a type using appropriate syntax */
  c_print_typedef,		/* Print a typedef using appropriate syntax */
  c_e2k_val_print,		/* Print a value using appropriate syntax with
                                   a special treatment for registers' values */
  c_value_print,		/* Print a top-level value */
  default_read_var_value,       /* la_read_var_value */
  NULL,				/* Language specific skip_trampoline */
  NULL,				/* name_of_this */
  true,				/* la_store_sym_names_in_linkage_form_p */
  basic_lookup_symbol_nonlocal,	/* lookup_symbol_nonlocal */
  basic_lookup_transparent_type,/* lookup_transparent_type */
  NULL,				/* Language specific symbol demangler */
  NULL,
  NULL,				/* Language specific
                                   class_name_from_physname */
  c_op_print_tab,		/* expression operators for printing */
  1,				/* c-style arrays */
  0,				/* String lower bound */
  default_word_break_characters,
  default_collect_symbol_completion_matches,
  c_language_arch_info,
  default_print_array_index,
  default_pass_by_reference,
  c_watch_location_expression,
  NULL,				/* la_get_symbol_name_matcher  */
  iterate_over_symbols,
  default_search_name_hash,
  &c_varobj_ops,
  c_get_compile_context,
  c_compute_program
};

#endif /* 0  */

extern void _initialize_c_e2k_language (void);

void *dummy_ptr = (void *) &c_e2k_language_defn;
void
_initialize_c_e2k_language (void)
{
#if 0
  /* FIXME: GDB should be made aware of `c_e2k_language_defn' in some other way
     now that `add_language ()' is not supported, if you want tagged values to
     be treated correctly.  */
  add_language (&c_e2k_language_defn);
#endif /* 0  */
}
