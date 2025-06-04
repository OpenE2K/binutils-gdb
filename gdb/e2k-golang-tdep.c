/* Copyright (c) 2009-2025 AO MCST.
   Copyright (C) 1991-2025 Free Software Foundation, Inc.
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this program; if not, see
   <https://www.gnu.org/licenses/>.  */

#include "defs.h"

#include "extract-store-integer.h"

#include "arch-utils.h"
#include "xml-syscall.h"

#include "e2k-golang-tdep.h"
#include "linux-tdep.h"

#include "features/e2k-golang.c"

#include "target-descriptions.h"
#include "dwarf2/frame.h"

struct e2k_golang_gdbarch_tdep : gdbarch_tdep_base
{
};


static const char * const e2k_golang_register_names[] =
{
 "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
 "r8", "r9", "r10", "r11",
 "b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7",
 "pc"
};

/* Return the name of register REGNUM.  */
static const char *
e2k_golang_register_name (struct gdbarch *gdbarch, int regnum)
{

  internal_error (_("e2k_golang_register_name () should never be called"));
  return "";
}

static struct type *
e2k_golang_register_type (struct gdbarch *gdbarch, int regnum)
{
  internal_error (_("e2k_golang_register_type () should never be called"));
  return nullptr;
}

static const char *
e2k_golang_pseudo_register_name (struct gdbarch *gdbarch, int regnum)
{
  internal_error (_("invalid regnum"));
  return nullptr;

}

static struct type *
e2k_golang_pseudo_register_type (struct gdbarch *gdbarch, int regnum)
{    
  internal_error (_("invalid regnum"));
  return nullptr;
}



static enum return_value_convention
e2k_golang_return_value (struct gdbarch  *gdbarch,
			 struct value *function,
			 struct type *type,
			 struct regcache *regcache,
			 struct value **read_value,
			 const gdb_byte *writebuf)
{
  return RETURN_VALUE_REGISTER_CONVENTION;
}

static CORE_ADDR
e2k_golang_skip_prologue (struct gdbarch *gdbarch, CORE_ADDR pc)
{
  return pc;
}


static LONGEST
e2k_golang_get_syscall_number (struct gdbarch *gdbarch,
			       thread_info *thread)
{
  struct regcache *regcache = get_thread_regcache (thread);
  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
  /* The content of a register.  */
  gdb_byte buf[8];
  /* The result.  */
  LONGEST ret;

  /* Getting the system call number from the register.
     When dealing with the e2k architecture, this information
     is stored at the %b[0] register.  */
  regcache->raw_read (E2K_GOLANG_B0_REGNUM, buf);
  ret = extract_signed_integer (buf, 8, byte_order);
  return ret;
}


static int
e2k_golang_validate_tdesc_p (e2k_golang_gdbarch_tdep *tdep,
			     const struct target_desc *tdesc,
			     struct tdesc_arch_data *tdesc_data)
{
  const struct tdesc_feature *the_only_feature
    = tdesc_find_feature (tdesc, "org.mcst.gdb.e2k.golang");

  if (the_only_feature == nullptr)
    return 0;
  
  int i, valid_p = 1;
  for (i = 0; i < NUM_E2K_GOLANG_RAW_REGS; i++)
    valid_p &= tdesc_numbered_register (the_only_feature, tdesc_data, i,
					e2k_golang_register_names[i]);

  return valid_p;
}

static int
e2k_golang_breakpoint_kind_from_pc (struct gdbarch *gdbarch, CORE_ADDR *pcptr)
{
  /* SETSFT has the minimal possible instruction size of 8 bytes on E2K.  */
  return 8;
}

static const gdb_byte *
e2k_golang_sw_breakpoint_from_kind (struct gdbarch *gdbarch,
				    int kind, int *size)
{
  static constexpr gdb_byte e2k_golang_setsft[]
    = { 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28 };

  *size = kind;
  return e2k_golang_setsft;
}


static struct gdbarch *
e2k_golang_gdbarch_init (struct gdbarch_info info, struct gdbarch_list *arches)
{
  /* If there is already a candidate, use it.  */
  arches = gdbarch_list_lookup_by_info (arches, &info);
  if (arches != NULL)
    return arches->gdbarch;

  /* Allocate space for the new architecture.  */
  gdbarch *gdbarch
    = gdbarch_alloc (&info, gdbarch_tdep_up (new e2k_golang_gdbarch_tdep));

  /* GDBARCH without target description is actually unusable for
     e2k_golang. Set the  number of registers to zero so that nobody ever
     attempts to call non-target description methods to obtain their names
     and types.  */
  set_gdbarch_num_regs (gdbarch, 0);
  set_gdbarch_num_pseudo_regs (gdbarch, 0);
  set_gdbarch_register_name (gdbarch, e2k_golang_register_name);
  set_gdbarch_register_type (gdbarch, e2k_golang_register_type);

  const struct target_desc *tdesc = info.target_desc;
  if (! tdesc_has_registers (tdesc))
    tdesc = tdesc_e2k_golang;

  gdb_assert (tdesc_has_registers (tdesc));

  e2k_golang_gdbarch_tdep *tdep
    = gdbarch_tdep<e2k_golang_gdbarch_tdep> (gdbarch);
  tdesc_arch_data_up tdesc_data = tdesc_data_alloc ();

  if (! e2k_golang_validate_tdesc_p (tdep, tdesc, tdesc_data.get ()))
    {
      gdbarch_free (gdbarch);
      return nullptr;
    }

  set_gdbarch_num_regs (gdbarch, NUM_E2K_GOLANG_RAW_REGS);
  set_gdbarch_num_pseudo_regs (gdbarch, NUM_E2K_GOLANG_PSEUDO_REGS);

  set_gdbarch_sp_regnum (gdbarch, E2K_GOLANG_R0_REGNUM + 8);
  set_gdbarch_pc_regnum (gdbarch, E2K_GOLANG_PC_REGNUM);

  set_tdesc_pseudo_register_type (gdbarch, e2k_golang_pseudo_register_type);
  set_tdesc_pseudo_register_name (gdbarch, e2k_golang_pseudo_register_name);
  tdesc_use_registers (gdbarch, tdesc, std::move (tdesc_data));

  set_gdbarch_return_value_as_value (gdbarch, e2k_golang_return_value);
  set_gdbarch_skip_prologue (gdbarch, e2k_golang_skip_prologue);

  set_gdbarch_breakpoint_kind_from_pc (gdbarch,
				       e2k_golang_breakpoint_kind_from_pc);
  set_gdbarch_sw_breakpoint_from_kind (gdbarch,
				       e2k_golang_sw_breakpoint_from_kind);

  /* This is to match the fact that decreasing %SP will be used to evaluate
     frame id.  */
  set_gdbarch_inner_than (gdbarch, core_addr_lessthan);

  /* Hook in ABI-specific overrides, if they have been registered.  */
  gdbarch_init_osabi (info, gdbarch);

  return gdbarch;
}

static void
e2k_golang_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  linux_init_abi (info, gdbarch, 0);
  set_gdbarch_ptr_bit (gdbarch, 64);

  /* Functions for 'catch syscall'.  */
  set_xml_syscall_file_name (gdbarch, "syscalls/e2k-linux.xml");
  set_gdbarch_get_syscall_number (gdbarch,
				  e2k_golang_get_syscall_number);

  dwarf2_append_unwinders (gdbarch);
}


void _initialize_e2k_golang_tdep ();
void
_initialize_e2k_golang_tdep ()
{
  gdbarch_register (bfd_arch_e2k_golang, e2k_golang_gdbarch_init, NULL);
  gdbarch_register_osabi (bfd_arch_e2k_golang,
			  /* 64-bit forward-compatible elbrus-v2 is the
			     only supported machine in bfd_arch_e2k_golang
			     arch for now.  */
			  4 * bfd_mach_e2k_ev2,
			  /* Does this actually make any sense? Shouldn't we
			     implement something special for GOLANG?  */
			  GDB_OSABI_LINUX,
			  e2k_golang_init_abi);

  initialize_tdesc_e2k_golang ();
}
