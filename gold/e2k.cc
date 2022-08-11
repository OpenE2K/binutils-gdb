#include "gold.h"

#include <cstdlib>

#include "elfcpp.h"
#include "e2k.h"
#include "output.h"
#include "target.h"
#include "target-reloc.h"
#include "target-select.h"

namespace
{

using namespace gold;

// A class to handle the `.got.plt' section
class Output_data_got_plt_e2k : public Output_section_data_build
{
public:
  Output_data_got_plt_e2k(Layout*)
    : Output_section_data_build(8)
  { }

protected:
  void do_write(Output_file*)
  { }

  // Write to a map file.
  void
  do_print_to_mapfile(Mapfile* mapfile) const
  { mapfile->print_output_data(this, _("** GOT PLT")); }

};

// A class to handle the PLT data.
class Output_data_plt_e2k : public Output_section_data
{
public:
  Output_data_plt_e2k(Layout*, Output_data_got_plt_e2k*)
    : Output_section_data(8)
  { }

  // Add an entry to the PLT
  void
  add_entry(Symbol_table*, Layout*, Symbol*)
  { }

protected:
  void do_write(Output_file*)
  { }

  // Write to a map file.
  void
  do_print_to_mapfile(Mapfile* mapfile) const
  { mapfile->print_output_data(this, _("** PLT")); }
};

template<int size>
class Target_e2k : public Sized_target<size, false>
{
public:

  Target_e2k()
    : Sized_target<size, false>(&e2k_info),
      got_(NULL)
      
  {
  }

  // Process the relocations to determine unreferenced sections for
  // garbage collection.
  void
  gc_process_relocs(Symbol_table*,
		    Layout*,
		    Sized_relobj_file<size, false>*,
		    unsigned int,
		    unsigned int,
		    const unsigned char*,
		    size_t,
		    Output_section*,
		    bool,
		    size_t,
		    const unsigned char*)
  {
  }

  // Scan the relocations to look for symbol adjustments.
  void
  scan_relocs(Symbol_table*,
	      Layout*,
	      Sized_relobj_file<size, false>*,
	      unsigned int,
	      unsigned int,
	      const unsigned char*,
	      size_t,
	      Output_section*,
	      bool,
	      size_t,
	      const unsigned char*);

  // Relocate a section.
  void
  relocate_section(const Relocate_info<size, false>*,
		   unsigned int,
		   const unsigned char*,
		   size_t,
		   Output_section*,
		   bool,
		   unsigned char*,
		   typename elfcpp::Elf_types<size>::Elf_Addr,
		   section_size_type,
		   const Reloc_symbol_changes*);

  // Scan the relocs during a relocatable link.
  void
  scan_relocatable_relocs(Symbol_table*,
			  Layout*,
			  Sized_relobj_file<size, false>*,
			  unsigned int,
			  unsigned int,
			  const unsigned char*,
			  size_t,
			  Output_section*,
			  bool,
			  size_t,
			  const unsigned char*,
			  Relocatable_relocs*)
  {
  }

  // Scan the relocs for --emit-relocs.
  void
  emit_relocs_scan(Symbol_table*,
		   Layout*,
		   Sized_relobj_file<size, false>*,
		   unsigned int,
		   unsigned int,
		   const unsigned char*,
		   size_t,
		   Output_section*,
		   bool,
		   size_t,
		   const unsigned char*,
		   Relocatable_relocs*)
  {
  }

    // Emit relocations for a section.
  void
  relocate_relocs(const Relocate_info<size, false>*,
		  unsigned int,
		  const unsigned char*,
		  size_t,
		  Output_section*,
		  typename elfcpp::Elf_types<size>::Elf_Off,
		  unsigned char*,
		  typename elfcpp::Elf_types<size>::Elf_Addr,
		  section_size_type,
		  unsigned char*,
		  section_size_type)
  {
  }

  int64_t
  do_tls_offset_for_local(const Relobj*, unsigned int, unsigned int) const
  {
    return 2 * size / 8;
  }


  // Return the offset to use for the GOT_INDX'th got entry which is
  // for global tls symbol GSYM. Note that unlike `_bfd_e2k_elf_tpoff_base'
  // this function returns the value having an opposite sign. Moreover, here we
  // probably shouldn't care about subtraction of the output TLS section's VMA
  // since unlike LD the generic part of GOLD hasn't taken it into account when
  // calculating relocation for a TLS symbol prior to calling us (see
  // `Got_entry::write ()').
  // FIXME: take care of the output TLS section's alignment here. How am I going
  // to get access to it?
  int64_t
  do_tls_offset_for_global(Symbol*, unsigned int) const
  {
    return 2 * size / 8;
  }


protected:

  void
  do_adjust_elf_header(unsigned char*, int)
  { }

  void
  do_function_location(Symbol_location*) const
  { }

private:

  bool has_got_section() const
  { return this->got_ != NULL; }

  // Get the GOT section, creating it if necessary
  Output_data_got<size, false>*
  got_section(Symbol_table*, Layout*);

  // Create the PLT section.
  void
  make_plt_section(Symbol_table*, Layout*);

  // Create a PLT entry for a global symbol
  void
  make_plt_entry(Symbol_table* symtab, Layout* layout,
                 Symbol* gsym);

  // Return the address of the GOT.
  uint64_t
  got_address() const
  {
    // FIXME: what is explicit usage of `this->' needed for?
    if (this->got_ == NULL)
      return 0;

    return this->got_->address ();
  }

  Output_data_plt_e2k*
  make_data_plt(Layout* layout, Output_data_got_plt_e2k* got_plt)
  {
    return new Output_data_plt_e2k(layout, got_plt);
  }

  // The class which scans relocations.
  class Scan
  {
  public:
    void
    local(Symbol_table*, Layout*, Target_e2k*,
	  Sized_relobj_file<size, false>*,
	  unsigned int,
	  Output_section*,
	  const elfcpp::Rela<size, false>&, unsigned int,
	  const elfcpp::Sym<size, false>&,
	  bool);

    void
    global(Symbol_table*, Layout*, Target_e2k*,
	   Sized_relobj_file<size, false>*,
	   unsigned int,
	   Output_section*,
	   const elfcpp::Rela<size, false>&, unsigned int,
	   Symbol*);

    private:

    // FIXME: what can `static' mean for a private class member?
    static void
    unsupported_reloc_local(
                            Sized_relobj_file<size, false>*,
                            unsigned int);

    static void
    unsupported_reloc_global(Sized_relobj_file<size, false>*,
                             unsigned int r_type,
                             Symbol*);
  };

  // The class which implements a relocation.
  class Relocate
  {
    public:
    Relocate ()
    { }

    // Do a relocation. Return false if the caller should not issue
    // any warnings about this relocation.
    bool
    relocate(const Relocate_info<size, false> *,
             unsigned int,
             Target_e2k*,
             Output_section*,
             size_t,
             const unsigned char *preloc,
             const Sized_symbol<size>*,
             const Symbol_value<size>*,
             unsigned char*,
             typename elfcpp::Elf_types<size>::Elf_Addr,
             section_size_type);
  };

  // Information about this specific target which we pass to the
  // general Target structure.
  static const Target::Target_info e2k_info;

  // The types of GOT entries needed for this platform.
    enum Got_type
  {
    GOT_TYPE_STANDARD = 0,      // GOT entry for a regular symbol
    GOT_TYPE_TLS_IE = 1,        // GOT entry for TLS IE model
  };

  // The GOT section.
  Output_data_got<size, false>* got_;

  // The PLT section.
  Output_data_plt_e2k* plt_;

  // The GOT PLT section.
  Output_data_got_plt_e2k* got_plt_;
};

template<>
const Target::Target_info Target_e2k<32>::e2k_info =
{
  32,				// size
  false,			// is_big_endian
  elfcpp::EM_MCST_ELBRUS,	// machine_code
  false,			// has_make_symbol
  false,			// has_resolve
  false,			// has_code_fill
  false,			// is_default_stack_executable
  false,			// can_icf_inline_merge_sections
  '\0',				// wrap_char
  "/lib32/ld-linux.so.2",	// dynamic_linker
  0x00010000,			// default_text_segment_address
  64 * 1024,			// abi_pagesize (overridable by -z max-page-size)
  4 * 1024,			// common_pagesize (overridable by -z common-page-size)
  false,                	// isolate_execinstr
  0,                    	// rosegment_gap
  elfcpp::SHN_UNDEF,		// small_common_shndx
  elfcpp::SHN_UNDEF,		// large_common_shndx
  0,				// small_common_section_flags
  0,				// large_common_section_flags
  NULL,				// attributes_section
  NULL,				// attributes_vendor
  "_start",			// entry_symbol_name
  32,				// hash_entry_size
  elfcpp::SHT_PROGBITS,		// unwind_section_type
};

template<>
const Target::Target_info Target_e2k<64>::e2k_info =
{
  64,				// size
  false,			// is_big_endian
  elfcpp::EM_MCST_ELBRUS,	// machine_code
  false,			// has_make_symbol
  false,			// has_resolve
  false,			// has_code_fill
  false,			// is_default_stack_executable
  false,			// can_icf_inline_merge_sections
  '\0',				// wrap_char
  "/lib64/ld-linux.so.2",	// dynamic_linker
  0x00010000,			// default_text_segment_address
  64 * 1024,			// abi_pagesize (overridable by -z max-page-size)
  4 * 1024,			// common_pagesize (overridable by -z common-page-size)
  false,                	// isolate_execinstr
  0,                    	// rosegment_gap
  elfcpp::SHN_UNDEF,		// small_common_shndx
  elfcpp::SHN_UNDEF,		// large_common_shndx
  0,				// small_common_section_flags
  0,				// large_common_section_flags
  NULL,				// attributes_section
  NULL,				// attributes_vendor
  "_start",			// entry_symbol_name
  64,				// hash_entry_size
  elfcpp::SHT_PROGBITS,		// unwind_section_type
};

// Class for performing E2K-specific sophisticated relocations for which
// standard Relocate_functions class turns out to be unsuitable.
template<int size>
class E2k_relocate_functions
{
public:
  static void
  islocal(unsigned char* view)
  {
    typedef typename elfcpp::Swap<32, false>::Valtype Valtype;
    Valtype* wv = reinterpret_cast<Valtype*>(view);
    Valtype val = elfcpp::Swap<32, false>::readval(wv);
    Valtype reloc;

    // Zero out ALS.src1 bits. Don't I zero too many bits in fact? It would
    // suffice to toggle the least significant one in fact for the sake of this
    // relocation.
    val &= ~(0xff << 16);
    // For now pretend that the symbol is always a subject for a "local"
    // call.
    reloc = 0xc1 << 16;

    elfcpp::Swap<32, false>::writeval(wv, val | reloc);
  }

  static void
  islocal32(unsigned char* view)
  {
    typedef typename elfcpp::Swap<32, false>::Valtype Valtype;
    Valtype* wv = reinterpret_cast<Valtype*>(view);

    // For now pretend that the symbol is always a subject for a "local"
    // call.
    elfcpp::Swap<32, false>::writeval(wv, 0x1);
  }

  static void
  disp(unsigned char* view,
       const Sized_relobj_file<size, false>* object,
       const Symbol_value<size>* psymval,
       typename elfcpp::Elf_types<size>::Elf_Addr addend,
       typename elfcpp::Elf_types<size>::Elf_Addr address)
  {
    typedef typename elfcpp::Swap<32, false>::Valtype Valtype;
    Valtype* wv = reinterpret_cast<Valtype*>(view);
    Valtype val = elfcpp::Swap<32, false>::readval(wv);
    Valtype reloc = ((psymval->value(object, addend) - address)
                     >> 3);
    // Zero out 4 most significant bits. This is crucial if displacement
    // turns out to be negative. Can't I use an unsigned type when performing
    // right shift instead?
    reloc &= ~(0xf << 28);

    val &= (0xf << 28);


    elfcpp::Swap<32, false>::writeval(wv, val | reloc);
  }

  static void
  abs_lit(unsigned char* view,
          const Sized_relobj_file<size, false>* object,
          const Symbol_value<size>* psymval,
          typename elfcpp::Elf_types<size>::Elf_Addr addend)
  {
    typedef typename elfcpp::Swap<64, false>::Valtype Valtype;
    Valtype reloc = psymval->value(object, addend);

    reloc = ((reloc & 0xffffffff) << 32) | (reloc >> 32);
    elfcpp::Swap<64, false>::writeval(view, reloc);
  }

  static void
  pc_lit(unsigned char* view,
         const Sized_relobj_file<size, false>* object,
         const Symbol_value<size>* psymval,
         typename elfcpp::Elf_types<size>::Elf_Addr addend,
         typename elfcpp::Elf_types<size>::Elf_Addr address)
  {
    typedef typename elfcpp::Swap<64, false>::Valtype Valtype;
    Valtype reloc = psymval->value(object, addend) - address;

    reloc = ((reloc & 0xffffffff) << 32) | (reloc >> 32);
    elfcpp::Swap<64, false>::writeval(view, reloc);
  }
};

template<int size>
Output_data_got<size, false>*
Target_e2k<size>::got_section(Symbol_table* symtab,
                              Layout* layout)
{
  if (this->got_ == NULL)
    {
      gold_assert(symtab != NULL && layout != NULL);

      // When using `-z now', we can tread `.got.plt' as a relro section.
      // Without `-z now', it is modified after program startup by lazy
      // PLT relocations.
      bool is_got_plt_relro = parameters->options().now();
      Output_section_order got_order = (is_got_plt_relro
                                        ? ORDER_RELRO
                                        : ORDER_RELRO_LAST);
      Output_section_order got_plt_order = (is_got_plt_relro
                                            ? ORDER_RELRO
                                            : ORDER_NON_RELRO_FIRST);

      this->got_ = new Output_data_got<size, false>();
      layout->add_output_section_data(".got", elfcpp::SHT_PROGBITS,
				      (elfcpp::SHF_ALLOC
				       | elfcpp::SHF_WRITE),
				      this->got_, got_order, true);

      this->got_plt_ = new Output_data_got_plt_e2k(layout);
      layout->add_output_section_data(".got.plt", elfcpp::SHT_PROGBITS,
                                      (elfcpp::SHF_ALLOC | elfcpp::SHF_WRITE),
                                      this->got_plt_, got_plt_order,
                                      is_got_plt_relro);

      // The first three entries are reserved for the link-time address of the
      // `.dynamic' section (filled in by ld) and runtime addresses of the link
      // map and `_dl_fixup ()' (initialized by ld.so).
      this->got_plt_->set_current_data_size(3 * size / 8);

      if (!is_got_plt_relro)
        {
          // These entries can go into the relro segment.
          layout->increase_relro(3 * size / 8);
        }

      // Define _GLOBAL_OFFSET_TABLE_ at the start of the `.got.plt' section.
      symtab->define_in_output_data("_GLOBAL_OFFSET_TABLE_", NULL,
				    Symbol_table::PREDEFINED,
				    this->got_plt_,
				    0, 0, elfcpp::STT_OBJECT,
				    elfcpp::STB_LOCAL,
				    elfcpp::STV_HIDDEN, 0,
				    false, false);
    }

  return this->got_;

}

// Create the PLT section
template<int size>
void
Target_e2k<size>::make_plt_section(Symbol_table* symtab, Layout* layout)
{
  if (this->plt_ == NULL)
    {
      // Create the GOT sections first.
      this->got_section(symtab, layout);

      this->plt_ = this->make_data_plt(layout, this->got_plt_);
    }
}

// Create a PLT entry for a global symbol
template<int size>
void
Target_e2k<size>::make_plt_entry(Symbol_table* symtab, Layout* layout,
                                 Symbol* gsym)
{
  if (gsym->has_plt_offset())
    return;

  if (this->plt_ == NULL)
    this->make_plt_section(symtab, layout);

  this->plt_->add_entry(symtab, layout, gsym);
}

// Report an unsupported relocation against a local symbol.
template<int size>
void
Target_e2k<size>::Scan::unsupported_reloc_local(
                        Sized_relobj_file<size, false>* object,
                        unsigned int r_type)
{
  gold_error(_("%s: unsupported reloc %u against local symbol"),
	     object->name().c_str(), r_type);
}



// Scan a relocation for a local symbol.
template<int size>
void
Target_e2k<size>::Scan::local(
                        Symbol_table* symtab,
                        Layout* layout,
                        Target_e2k* target,
                        Sized_relobj_file<size, false>* object,
                        unsigned int,
                        Output_section*,
                        const elfcpp::Rela<size, false>& rela,
                        unsigned int r_type,
                        const elfcpp::Sym<size, false>&,
                        bool)
{
  switch (r_type)
    {
    case elfcpp::R_E2K_32_ABS:
    case elfcpp::R_E2K_32_PC:
    case elfcpp::R_E2K_64_ABS:
    case elfcpp::R_E2K_64_ABS_LIT:
    case elfcpp::R_E2K_64_PC_LIT:
      break;

    case elfcpp::R_E2K_TLS_IE:
      {
        Output_data_got<size, false>* got;
        unsigned int r_sym = elfcpp::elf_r_sym<size>(rela.get_r_info());
        got = target->got_section(symtab, layout);
        got->add_local_tls(object, r_sym, GOT_TYPE_TLS_IE);
      }
      break;

    case elfcpp::R_E2K_64_TLS_LE:
    case elfcpp::R_E2K_GOT:
    case elfcpp::R_E2K_GOTOFF:
    case elfcpp::R_E2K_64_GOTOFF_LIT:
    case elfcpp::R_E2K_DISP:
    case elfcpp::R_E2K_GOTPLT:
    case elfcpp::R_E2K_ISLOCAL:
    case elfcpp::R_E2K_ISLOCAL32:
      break;

    default:
      unsupported_reloc_local(object, r_type);
      break;
    }
}

// Report an unsupported relocation against a global symbol.
template<int size>
void
Target_e2k<size>::Scan::unsupported_reloc_global(
                        Sized_relobj_file<size, false>* object,
                        unsigned int r_type,
                        Symbol* gsym)
{
  gold_error(_("%s: unsupported reloc %u against global symbol %s"),
             object->name().c_str(), r_type, gsym->demangled_name().c_str());
}

// Scan a relocation for a global symbol.
template<int size>
void
Target_e2k<size>::Scan::global(
                        Symbol_table* symtab,
                        Layout* layout,
                        Target_e2k* target,
                        Sized_relobj_file<size, false>* object,
                        unsigned int,
                        Output_section*,
                        const elfcpp::Rela<size, false>&,
                        unsigned int r_type,
                        Symbol* gsym)
{
  if (!target->has_got_section()
      && strcmp (gsym->name(), "_GLOBAL_OFFSET_TABLE_") == 0)
    target->got_section(symtab, layout);

  switch (r_type)
    {
    case elfcpp::R_E2K_32_ABS:
    case elfcpp::R_E2K_32_PC:
    case elfcpp::R_E2K_64_ABS:
    case elfcpp::R_E2K_64_ABS_LIT:
    case elfcpp::R_E2K_64_PC_LIT:
      break;

    case elfcpp::R_E2K_TLS_IE:
      {
        Output_data_got<size, false>* got;
        got = target->got_section(symtab, layout);
        got->add_global_tls(gsym, GOT_TYPE_TLS_IE);
      }
      break;

    case elfcpp::R_E2K_64_TLS_LE:
      break;

    case elfcpp::R_E2K_GOT:
      {
        Output_data_got<size, false>* got;
        got = target->got_section(symtab, layout);
        got->add_global(gsym, GOT_TYPE_STANDARD);
      }
      break;

    case elfcpp::R_E2K_GOTOFF:
    case elfcpp::R_E2K_64_GOTOFF_LIT:
      break;

    case elfcpp::R_E2K_DISP:
      if (gsym->needs_plt_entry())
        target->make_plt_entry(symtab, layout, gsym);
      break;

    case elfcpp::R_E2K_GOTPLT:
    case elfcpp::R_E2K_ISLOCAL:
    case elfcpp::R_E2K_ISLOCAL32:      
      break;

    default:
      unsupported_reloc_global(object, r_type, gsym);
      break;
    }
}

// Scan relocations for a section.

template <int size>
void
Target_e2k<size>::scan_relocs(
                        Symbol_table* symtab,
                        Layout* layout,
                        Sized_relobj_file<size, false>* object,
                        unsigned int data_shndx,
                        unsigned int sh_type,
                        const unsigned char* prelocs,
                        size_t reloc_count,
                        Output_section* output_section,
                        bool needs_special_offset_handling,
                        size_t local_symbol_count,
                        const unsigned char* plocal_symbols)
{
  typedef Target_e2k<size> E2k;
  typedef typename Target_e2k<size>::Scan Scan;

  typedef gold::Default_classify_reloc<elfcpp::SHT_RELA, size, false>
    Classify_reloc;


  if (sh_type == elfcpp::SHT_REL)
    {
      gold_error (_("%s: unsupported REL reloc section"),
                  object->name().c_str());
      return;
    }

  gold::scan_relocs<size, false, E2k, Scan, Classify_reloc>(
    symtab,
    layout,
    this,
    object,
    data_shndx,
    prelocs,
    reloc_count,
    output_section,
    needs_special_offset_handling,
    local_symbol_count,
    plocal_symbols);
}


// Perform a relocation.

template<int size>
bool
Target_e2k<size>::Relocate::relocate(
                        const Relocate_info<size, false>* relinfo,
                        unsigned int,
                        Target_e2k* target,
                        Output_section*,
                        size_t relnum,
                        const unsigned char *preloc,
                        const Sized_symbol<size>* gsym,
                        const Symbol_value<size>* psymval,
                        unsigned char* view,
                        typename elfcpp::Elf_types<size>::Elf_Addr address,
                        section_size_type)
{
  /* The next two variables used to be parameters to this function.  */
  const elfcpp::Rela<size, false> rela(preloc);
  unsigned int r_type = elfcpp::elf_r_type<size>(rela.get_r_info());
    
  typedef E2k_relocate_functions<size> Reloc;
  const Sized_relobj_file<size, false>* object = relinfo->object;
  typename elfcpp::Elf_types<size>::Elf_Addr addend = rela.get_r_addend();

  switch (r_type)
    {
    case elfcpp::R_E2K_64_ABS:
      Relocate_functions<size, false>::rela64(view, object, psymval, addend);
      break;
    case elfcpp::R_E2K_32_ABS:
      Relocate_functions<size, false>::rela32(view, object, psymval, addend);
      break;

    case elfcpp::R_E2K_32_PC:
    case elfcpp::R_E2K_64_ABS_LIT:
      Reloc::abs_lit(view, object, psymval, addend);
      break;

    case elfcpp::R_E2K_64_PC_LIT:
      Reloc::pc_lit(view, object, psymval, addend, address);
      break;

    case elfcpp::R_E2K_TLS_IE:
      {
        unsigned int got_offset;
        if (gsym != NULL)
          got_offset = gsym->got_offset(GOT_TYPE_TLS_IE);
        else
          {
            unsigned int r_sym = elfcpp::elf_r_sym<size>(rela.get_r_info());
            got_offset = object->local_got_offset(r_sym, GOT_TYPE_TLS_IE);
          }

          Relocate_functions<size,false>::rela32(view, got_offset, addend);
        }
      break;

    case elfcpp::R_E2K_64_TLS_LE:
      break;

    case elfcpp::R_E2K_GOT:
      {
        unsigned int got_offset;
        got_offset = gsym->got_offset(GOT_TYPE_STANDARD);
        Relocate_functions<size,false>::rela32(view, got_offset, addend);
      }
      break;

    case elfcpp::R_E2K_GOTOFF:
    case elfcpp::R_E2K_64_GOTOFF_LIT:
      {
        unsigned int got_offset;
        got_offset = psymval->value(object, 0) - target->got_address ();
        Relocate_functions<size,false>::rela32(view, got_offset, addend);
      }
      break;

    case elfcpp::R_E2K_DISP:
      Reloc::disp(view, object, psymval, addend, address);
      break;
        

    case elfcpp::R_E2K_GOTPLT:
      break;

    case elfcpp::R_E2K_ISLOCAL:
      Reloc::islocal(view);
      break;

    case elfcpp::R_E2K_ISLOCAL32:
      Reloc::islocal32(view);
      break;

    default:
        gold_error_at_location(relinfo, relnum, rela.get_r_offset(),
                               _("unexpected reloc %u in object file"),
                               r_type);
    }

  return true;
}

// Relocate section data.

template<int size>
void
Target_e2k<size>::relocate_section(
                            const Relocate_info<size, false> *relinfo,
                            unsigned int sh_type,
                            const unsigned char *prelocs,
                            size_t reloc_count,
                            Output_section *output_section,
                            bool needs_special_offset_handling,
                            unsigned char *view,
                            typename elfcpp::Elf_types<size>::Elf_Addr address,
                            section_size_type view_size,
                            const Reloc_symbol_changes *reloc_symbol_changes)
{
  typedef Target_e2k<size> E2k;
  typedef gold::Default_classify_reloc<elfcpp::SHT_RELA, size, false>
    Classify_reloc;

  gold_assert(sh_type == elfcpp::SHT_RELA);
  gold::relocate_section<size, false, E2k, E2k::Relocate,
                         gold::Default_comdat_behavior, Classify_reloc>(
    relinfo,
    this,
    prelocs,
    reloc_count,
    output_section,
    needs_special_offset_handling,
    view,
    address,
    view_size,
    reloc_symbol_changes);
                                   
    }


// The selector for E2K object files.

template<int size>
class Target_selector_e2k : public Target_selector
{
public:
  Target_selector_e2k()
    : Target_selector(elfcpp::EM_MCST_ELBRUS, size, false,
                      (size == 64 ? "elf64-e2k" : "elf32-e2k"),
                      (size == 64 ? "elf64_e2k" : "elf32_e2k"))
  { }

  virtual Target*
  do_instantiate_target()
  { return new Target_e2k<size>(); }
};

Target_selector_e2k<32> target_selector_e2k32;
Target_selector_e2k<64> target_selector_e2k64;

} // End anonymous namespace.
