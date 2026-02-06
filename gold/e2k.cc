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
template<int size, bool pm>
class Output_data_got_plt_e2k : public Output_section_data_build
{
public:
  Output_data_got_plt_e2k(Layout *layout)
    : Output_section_data_build(pm ? 16 : size / 8),
      layout_(layout)
  { }

protected:
  void do_write(Output_file*);

  // Write to a map file.
  void
  do_print_to_mapfile(Mapfile* mapfile) const
  { mapfile->print_output_data(this, _("** GOT PLT")); }

private:
  // A pointer to the Layout class, so that we can find the .dynamic
  // section when we write out the GOT PLT section.
  Layout* layout_;
};

// Write the first three reserved words of the .got.plt section.
// The remainder of the section is written while writing the PLT
// in Output_data_plt_i386::do_write.
template<int size, bool pm>
void
Output_data_got_plt_e2k<size, pm>::do_write(Output_file *of)
{
  // The first entry in the GOT is the address of the .dynamic section
  // aka the PT_DYNAMIC segment.  The next two entries are reserved.
  // We saved space for them when we created the section in
  // Target_e2k::got_section.
  const off_t got_file_offset = this->offset();
  gold_assert(this->data_size() >= 3 * (size / 8));
  unsigned char* const got_view = of->get_output_view(got_file_offset, 3 * (size / 8));
  Output_section* dynamic = this->layout_->dynamic_section();
  uint64_t dynamic_addr = dynamic == NULL ? 0 : dynamic->address();
  elfcpp::Swap<size, false>::writeval(got_view, dynamic_addr);
  memset(got_view + (size / 8), 0, 2 * (size / 8));
  of->write_output_view(got_file_offset, 3 * (size / 8), got_view);
}

// A class to handle the PLT data.
template<int size, bool pm>
class Output_data_plt_e2k : public Output_section_data
{
public:
  typedef Output_data_reloc<elfcpp::SHT_RELA, true, size, false> Reloc_section;

  Output_data_plt_e2k(Layout *layout, Output_data_got_plt_e2k<size, pm> *got_plt)
    : Output_section_data(8), got_plt_ (got_plt), count_ (0)
  {
    this->rela_ = new Reloc_section(false);
    layout->add_output_section_data(".rela.plt", elfcpp::SHT_RELA,
				    elfcpp::SHF_ALLOC, this->rela_,
				    ORDER_DYNAMIC_PLT_RELOCS, false);
  }

  // Return the PLT address to use for a global symbol.
  uint64_t
  address_for_global(const Symbol*);

  // Return the .rela.plt section data.
  Reloc_section*
  rela_plt()
  { return this->rela_; }


  // Add an entry to the PLT
  void
  add_entry (Symbol_table*, Layout*, Symbol*);

protected:
  void do_write(Output_file*);

  // Write to a map file.
  void
  do_print_to_mapfile(Mapfile* mapfile) const
  { mapfile->print_output_data(this, _("** PLT")); }

private:
  // Return the size of a PLT entry.
  unsigned int
  get_plt_entry_size() const
  { return plt_entry_size; }

  // Fill a normal PLT entry, given the pointer to the entry's data in the
  // section, the runtime address of the GOT, the offset into the GOT of
  // the corresponding slot, the offset into the relocation section of the
  // corresponding reloc, and the offset of this entry within the whole
  // PLT.  Return the offset from this PLT entry's runtime address that
  // should be used to compute the initial value of the GOT slot.
  unsigned int
  fill_plt_entry(unsigned char* pov,
		 typename elfcpp::Elf_types<size>::Elf_Addr,
		 unsigned int,
		 unsigned int,
		 unsigned int);

  // Set the final size.
  void
  set_final_data_size()
  {
    this->set_data_size (plt_header_size
			 + this->count_ * this->get_plt_entry_size());
  }


  // The reloc section.
  Reloc_section* rela_;

  // The .got.plt section.
  Output_data_got_plt_e2k<size, pm> *got_plt_;

  // The number of PLT entries.
  unsigned int count_;

  // A PLT PIC header.
  static const unsigned int link_map_addr_literal_offset;
  static const unsigned int dl_fixup_addr_literal_offset;
  static const unsigned int plt_header[];
  static const int plt_header_size;

  // A PLT PIC entry.
  static const unsigned int load_target_literal_offset;
  static const unsigned int plt_entry[];
  static const int plt_entry_size;
};

template<int size, bool pm>
void
Output_data_plt_e2k<size,pm>::add_entry (Symbol_table *, Layout *,
					 Symbol *gsym)
{
  gold_assert(!gsym->has_plt_offset());

  gsym->set_plt_offset(plt_header_size
		       + (this->count_) * this->get_plt_entry_size());
  ++this->count_;

  section_offset_type got_offset = this->got_plt_->current_data_size();

  // Every PLT entry needs a GOT entry which points back to the
  // PLT entry (this will be changed by the dynamic linker,
  // normally lazily when the function is called).
  this->got_plt_->set_current_data_size(got_offset + (pm ? 16 : size / 8));

  gsym->set_needs_dynsym_entry();
  this->rela_->add_global(gsym,
			 ((pm || size == 32)
			  ? elfcpp::R_E2K_32_JMP_SLOT
			  : elfcpp::R_E2K_64_JMP_SLOT),
			  this->got_plt_,
			  got_offset,
			  0 /* addend  */);
}

#define LOAD_TARGET(ind)						\
  /* ALS0  */ (0x79c0d980 | ind),  /* ldgdq,0 0x0, _f32s,_lts1 0x44444444, %qr{ind}  */ \
  /* ALS2  */ (0x79c0d980 | (ind + 1))


#define MOVTD_TARGET(ind)						\
  /* HS    */ 0x04000001,						\
  /* ALS0  */ (0x61c080d1 | (ind << 8))  /* movtd,0 %dr{ind}, %ctpr1  */

#define MOVTQ_PAIR(src, dst)						\
  /* HS    */ 0x6db00034,						\
  /* ALS0  */ (0x57c08080 | ((src + 0) << 8) | (dst + 0)),  /* movtq,0 %qr{src}, %qr{dst}  */ \
  /* ALS1  */ (0x57c08080 | ((src + 1) << 8) | (dst + 1)),		\
  /* ALS3  */ (0x57c08080 | ((src + 2) << 8) | (dst + 2)),  /* movtq,3 %qr{src+2}, %qr{dst+2}  */ \
  /* ALS4  */ (0x57c08080 | ((src + 3) << 8) | (dst + 3)),		\
  /* ALES  */ 0x01c001c0,						\
  /* ALES  */ 0x01c001c0,						\
  /* LTS0  */ 0x00000000



#define CALL_WBS(wbs)							\
  /* CS1   */ (0x50000000 | wbs)  /* call %ctpr1, wbs = wbs  */

#define WSZ(wsz)				\
  /* LTS0  */ (0x00000010 | (wsz << 5))

template<> const unsigned int
Output_data_plt_e2k<64, true>::load_target_literal_offset = 0x20 + 0x18;

template<>
const unsigned int Output_data_plt_e2k<64, true>::
plt_entry[] =
{
    /*   0:	*/
  /* HS    */ 0x0400d034,
  /* SS    */ 0x80000020,  /* ipd 2  */
  /* ALS0  */ 0x10c0d994,  /* addd,0 0x0, _f32s,_lts1 0x76543210, %r20  */
  /* CS0   */ 0x00000000,  /* ibranch 0x0  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x10, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000210,

  /*   0:  */
  /* HS    */ 0x14508033,
  /* ALS{0,2} */ LOAD_TARGET (16),
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x{8,10}, nfx = 0x1  */
  /* ALES0 */ 0x01c00000,
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x44444444,
  /* LTS0  */ WSZ (0x10),

  MOVTD_TARGET (16),
  MOVTQ_PAIR (0, 16),
  MOVTQ_PAIR (4, 20),
  MOVTQ_PAIR (8, 24),
  MOVTQ_PAIR (12, 28),

  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ CALL_WBS (0x8),
  /* LTS0  */ 0x00000000,

  /* HS    */ 0x00005012,
  /* SS    */ 0x80000000,  /* ipd 2  */
  /* CS0   */ 0xf0000000,  /* return %ctpr3  */
  /* LTS0  */ 0x00000000,

  MOVTQ_PAIR (16, 0),
  MOVTQ_PAIR (20, 4),
  MOVTQ_PAIR (24, 8),
  MOVTQ_PAIR (28, 12),

  /* HS    */ 0x00001001,
  /* SS    */ 0x80000c20,  /* ct %ctpr3  */
  /*                          ipd 2  */
};

template<> const int Output_data_plt_e2k<64, true>::plt_entry_size = sizeof (plt_entry);


// TODO: merge this definition with the coinciding 32-bit non-PM value.
template<> const unsigned int
Output_data_plt_e2k<64, false>::load_target_literal_offset = 0x20 + 0x24;

template<>
const unsigned int Output_data_plt_e2k<64, false>::
plt_entry[] =
{
    /*   0:	*/
  /* HS    */ 0x0400d034,
  /* SS    */ 0x80000020,  /* ipd 2  */
  /* ALS0  */ 0x11c0d989,  /* addd,0 0x0, _f32s,_lts1 0x76543210, %r9  */
  /* CS0   */ 0x00000000,  /* ibranch 0x0  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

  /* 0008<000000000070> HS    */ 0x041080a2, /* :nop 1  */
  /*                    ALS0  */ 0x3f81c088, /*  rrd,0 %ip, %dr8  */
  /*                    CS1   */ 0x00000000, /*  setwd wsz = 0x8, nfx = 0x1  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x00000110,
  /* 0009<000000000088> HS    */ 0x04000111, /* :nop 2  */
  /*                    ALS0  */ 0x6788d888, /*  ldd,0 [ %dr8 + _f32s,_lts0 0x44444444 ], %dr8  */
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x44444444,
  /* 0010<000000000098> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c088d1, /*  movtd,0 %dr8, %ctpr1  */
  /* 0011<0000000000a0> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

template<> const int Output_data_plt_e2k<64, false>::plt_entry_size = sizeof (plt_entry);

// TODO: merge this definition with the coinciding 32-bit non-PM value.
template<> const unsigned int
Output_data_plt_e2k<32, false>::load_target_literal_offset = 0x20 + 0x24;

template<>
const unsigned int Output_data_plt_e2k<32, false>::
plt_entry[] =
{
  /*   0:	*/
  /* HS    */ 0x0400d034,
  /* SS    */ 0x80000020,  /* ipd 2  */
  /* ALS0  */ 0x11c0d989,  /* addd,0 0x0, _f32s,_lts1 0x76543210, %r9  */
  /* CS0   */ 0x00000000,  /* ibranch 0x0  */
  /* CS1   */ 0x00000000,  /* setwd wsz = 0x8, nfx = 0x1  */
  /* LTS2  */ 0x00000000,
  /* LTS1  */ 0x76543210,
  /* LTS0  */ 0x00000110,

  /* 0008<000000000070> HS    */ 0x041080a2, /* :nop 1  */
  /*                    ALS0  */ 0x3e81c088, /*  rrs,0 %ip, %r8  */
  /*                    CS1   */ 0x00000000, /*  setwd wsz = 0x8, nfx = 0x1  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x00000000,
  /*                    LTS0  */ 0x00000110,
  /* 0009<000000000088> HS    */ 0x04100111, /* :nop 2  */
  /*                    ALS0  */ 0x6688d888, /*  ldgdw,0 [ %r8 + _f32s,_lts0 0x44444444 ], %r8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x44444444,
  /* 0010<000000000098> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f088d1, /*  getpl,0 %r8, %ctpr1  */
  /* 0011<0000000000a0> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

template<> const int Output_data_plt_e2k<32, false>::plt_entry_size = sizeof (plt_entry);


template<int size, bool pm>
unsigned int
Output_data_plt_e2k<size, pm>::fill_plt_entry
(unsigned char* pov,
 typename elfcpp::Elf_types<size>::Elf_Addr got_plt_address,
 unsigned int got_plt_offset,
 unsigned int plt_offset,
 unsigned int plt_rela_offset)
{
  memcpy (pov, plt_entry, plt_entry_size);

  /* Fill secondary PLT entry.  */
  elfcpp::Swap<32, false>::writeval (pov + 24, plt_rela_offset);

  /* TODO: set disp for IBRANCH in the secondary PLT entry.  */
  elfcpp::Swap<32, false>::writeval (pov + 12,
				     /* The fact that `CSO.opc == 0' for
					IBRANCH is implicitly taken into
					account here.  */
				     ((-1U * plt_offset) >> 3) & 0x0fffffffU);

  /* Fixx primary PLT entry.  */
  elfcpp::Swap<32, false>::writeval (pov + load_target_literal_offset /* 32 + 36  */,
				     (got_plt_address
				      + got_plt_offset
				      - (! pm
					 ? (this->address () + plt_offset + 32)
					 : 0)));

  return 0;
}


template<> const unsigned int
Output_data_plt_e2k<64, true>::link_map_addr_literal_offset = 0x1c;

// Not used in PM.
// template<> const unsigned int
// Output_data_plt_e2k<64, true>::dl_fixup_addr_literal_offset;

#define LOAD_LINK_MAP_DL_FIXUP(reg1, reg2)				\
    /* HS    */ 0xb6d00034,						\
    /* ALS0  */ (0x79c0d880 | reg1),  /* ldgdq,0 0x0, _f32s,_lts0 0x12345678, %qr{reg1}  */ \
    /* ALS2  */ (0x79c0d880 | (reg1 + 1)),				\
    /* ALS3  */ (0x79d0d880 | reg2),  /* ldgdq,3 0x10, _f32s,_lts0 0x12345678, %qr{reg2}  */ \
    /* ALS5  */ (0x79d0d880 | (reg2 + 1)),				\
    /* ALES03*/ 0x01c001c0,						\
    /* LTS1  */ 0x00000000,						\
    /* LTS0  */ 0x12345678



template<>
const unsigned int Output_data_plt_e2k<64, true>::
plt_header[] = 
{
  LOAD_LINK_MAP_DL_FIXUP (18, 22),

  MOVTD_TARGET(22),

  /*  28:	*/
  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ CALL_WBS (0x8),
  /* LTS0  */ 0x00000000,

  MOVTD_TARGET (16),
  MOVTQ_PAIR (0, 16),
  MOVTQ_PAIR (4, 20),
  MOVTQ_PAIR (8, 24),
  MOVTQ_PAIR (12, 28),

  /* HS    */ 0x00009012,
  /* SS    */ 0x80000420,  /* ipd 2  */
  /* CS1   */ CALL_WBS (0x8),			
  /* LTS0  */ 0x00000000,

  /* HS    */ 0x00004001,
  /* CS0   */ 0xf0000000,  /* return %ctpr3  */

  MOVTQ_PAIR (16, 0),
  MOVTQ_PAIR (20, 4),
  MOVTQ_PAIR (24, 8),
  MOVTQ_PAIR (28, 12),

  /* HS    */ 0x00001001,
  /* SS    */ 0x80000c20,  /* ct %ctpr3  */
  /*                          ipd 2  */

};

template<> const int Output_data_plt_e2k<64, true>::plt_header_size = sizeof (plt_header);

// These ones are the same in ordinary 32- and 64-bit modes. TODO: how could
// they be shared?
template<> const unsigned int
Output_data_plt_e2k<64, false>::link_map_addr_literal_offset = 0x24;

template<> const unsigned int
Output_data_plt_e2k<64, false>::dl_fixup_addr_literal_offset = 0x20;

template<>
const unsigned int Output_data_plt_e2k<64, false>::
plt_header[] = 
{
  /* 0000<000000000000> HS    */ 0x04100091, /* header: nop 1  */
  /*                    ALS0  */ 0x3f81c088, /*  rrd,0 %ip, %dr8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x00000000,
  /* 0001<000000000010> HS    */ 0x14000122, /* :nop 2  */
  /*                    ALS0  */ 0x6788d888, /*  ldd,0 [ %dr8 + _f32s,_lts0 0x11111111 ], %dr8  */
  /*                    ALS2  */ 0x6788d98a, /*  ldd,2 [ %dr8 + _f32s,_lts1 0x22222222 ], %dr10  */
  /*                    LTS2  */ 0x00000000,
  /*                    LTS1  */ 0x22222222,
  /*                    LTS0  */ 0x11111111,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c08ad1, /*  movtd,0 %dr10, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00009012, /* :  */
  /*                    SS    */ 0x80000420, /*  ipd 2  */
  /*                    CS1   */ 0x50000004, /*  call %ctpr1, wbs = 0x4  */
  /*                    LTS0  */ 0x00000000,
  /* 0004<000000000040> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x61c088d1, /*  movtd,0 %dr8, %ctpr1  */
  /* 0005<000000000048> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

template<> const int Output_data_plt_e2k<64, false>::plt_header_size = sizeof (plt_header);

// These ones are the same in ordinary 32- and 64-bit modes. TODO: how could
// they be shared?
template<> const unsigned int
Output_data_plt_e2k<32, false>::link_map_addr_literal_offset = 0x24;

template<> const unsigned int
Output_data_plt_e2k<32, false>::dl_fixup_addr_literal_offset = 0x20;

template<>
const unsigned int Output_data_plt_e2k<32, false>::
plt_header[] = 
{
  /* 0000<000000000000> HS    */ 0x04100091, /* M_0: nop 1  */
  /*                    ALS0  */ 0x3e81c088, /*  rrs,0 %ip, %r8  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS0  */ 0x00000000,
  /* 0001<000000000010> HS    */ 0x14500122, /* :nop 2  */
  /*                    ALS0  */ 0x6688d888, /*  ldgdw,0 [ %r8 + _f32s,_lts0 0x11111111 ], %r8  */
  /*                    ALS2  */ 0x6688d98a, /*  ldgdw,2 [ %r8 + _f32s,_lts1 0x22222222 ], %r10  */
  /*                    ALES  */ 0x01c00000,
  /*                    LTS1  */ 0x22222222,
  /*                    LTS0  */ 0x11111111,
  /* 0002<000000000028> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f08ad1, /*  getpl,0 %r10, %ctpr1  */
  /* 0003<000000000030> HS    */ 0x00009012, /* :  */
  /*                    SS    */ 0x80000420, /*  ipd 2  */
  /*                    CS1   */ 0x50000004, /*  call %ctpr1, wbs = 0x4  */
  /*                    LTS0  */ 0x00000000,
  /* 0004<000000000040> HS    */ 0x04000001, /* :  */
  /*                    ALS0  */ 0x63f088d1, /*  getpl,0 %r8, %ctpr1  */
  /* 0005<000000000048> HS    */ 0x00001001, /* :  */
  /*                    SS    */ 0x80000420, /*  ct %ctpr1  */
                                             /*  ipd 2  */
};

template<> const int Output_data_plt_e2k<32, false>::plt_header_size = sizeof (plt_header);


template<int size, bool pm>
void Output_data_plt_e2k<size, pm>::do_write (Output_file *of)
{
  /* Consider making it static and get rid of the local variable everywhere.  */
  const unsigned int got_entry_size = pm ? 16 : (size / 8);

  const off_t offset = this->offset();
  const section_size_type oview_size =
    convert_to_section_size_type(this->data_size());
  unsigned char * const oview = of->get_output_view(offset, oview_size);

  const off_t got_plt_file_offset = this->got_plt_->offset();

  const section_size_type got_plt_size =
    convert_to_section_size_type (this->got_plt_->data_size());

  unsigned char * const got_plt_view =
    of->get_output_view (got_plt_file_offset, got_plt_size);

  unsigned char *pov = oview;
  typename elfcpp::Elf_types<size>::Elf_Addr plt_address = this->address();
  /* Why is TYPENAME is not needed on i386 specifying 32 in place of SIZE?  */
  typename elfcpp::Elf_types<size>::Elf_Addr got_plt_address = this->got_plt_->address();

  memcpy (pov, plt_header, plt_header_size);
  /* To load link_map.  */
  elfcpp::Swap<32, false>::writeval (pov + link_map_addr_literal_offset /* 0x24  */,
				     (got_plt_address
				      + got_entry_size
				      - (! pm ? plt_address : 0)));

  /* To load `&_dl_fixup'.  */
  if (! pm)
    elfcpp::Swap<32, false>::writeval (pov + dl_fixup_addr_literal_offset /* 0x20  */,
				       (got_plt_address
					+ 2 * got_entry_size
					- plt_address));

  pov += plt_header_size;


  unsigned char *got_plt_pov = got_plt_view + 3 * got_entry_size;

  const int rela_size = elfcpp::Elf_sizes<size>::rela_size;



  unsigned int plt_offset = plt_header_size;
  unsigned int plt_rela_offset = 0;
  unsigned int got_plt_offset = 3 * got_entry_size;
  const unsigned int count = this->count_;

  for (unsigned int i = 0;
       i < count;
       ++i,
	 pov += this->get_plt_entry_size(),
	 got_plt_pov += got_entry_size,
	 plt_offset += this->get_plt_entry_size(),
	 plt_rela_offset += rela_size,
	 got_plt_offset += got_entry_size)
    {
      // Set and adjust the PLT entry itself.
      unsigned int lazy_offset = this->fill_plt_entry(pov,
						      got_plt_address,
						      got_plt_offset,
						      plt_offset,
						      plt_rela_offset);

      // Set the entry in the GOT.
      elfcpp::Swap<!pm ? size : 32, false>::
	writeval (got_plt_pov, plt_address + plt_offset + lazy_offset);
    }


}

// Return the PLT address to use for a global symbol.
template <int size, bool pm>
uint64_t
Output_data_plt_e2k<size, pm>::address_for_global(const Symbol* gsym)
{
  uint64_t offset = 0;
#if 0
  if (gsym->type() == elfcpp::STT_GNU_IFUNC
      && gsym->can_use_relative_reloc(false))
    offset = (this->count_ + 1) * this->get_plt_entry_size();
#endif /* 0  */

  return (this->address() + offset + gsym->plt_offset()
	  /* Skip the secondary PLT entry so as execution is passed not
	     to it, but to the primary one.  */
	  + 32);
}


template<int size, bool pm>
class Target_e2k : public Sized_target<size, false>
{
public:
  typedef Output_data_reloc<elfcpp::SHT_RELA, true, size, false> Reloc_section;

  Target_e2k()
    : Sized_target<size, false>(&e2k_info),
      got_(NULL), plt_(NULL), got_plt_(NULL), rela_dyn_(NULL),
      tls_gdmod_got_offset_(-1U), machine(0)
      
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

  // Finalize the sections.
  void
  do_finalize_sections(Layout*, const Input_objects*, Symbol_table*);

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
  scan_relocatable_relocs(Symbol_table* symtab,
			  Layout* layout,
			  Sized_relobj_file<size, false>* object,
			  unsigned int data_shndx,
			  unsigned int sh_type,
			  const unsigned char* prelocs,
			  size_t reloc_count,
			  Output_section* output_section,
			  bool needs_special_offset_handling,
			  size_t local_symbol_count,
			  const unsigned char* plocal_symbols,
			  Relocatable_relocs* rr)
  {
    typedef gold::Default_scan_relocatable_relocs<gold::Default_classify_reloc<elfcpp::SHT_RELA, size, false> >
      Scan_relocatable_relocs;

    gold_assert(sh_type == elfcpp::SHT_RELA);

    gold::scan_relocatable_relocs<size, false, Scan_relocatable_relocs>(
      symtab,
      layout,
      object,
      data_shndx,
      prelocs,
      reloc_count,
      output_section,
      needs_special_offset_handling,
      local_symbol_count,
      plocal_symbols,
      rr);
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
  relocate_relocs(const Relocate_info<size, false>* relinfo,
		  unsigned int sh_type,
		  const unsigned char* prelocs,
		  size_t reloc_count,
		  Output_section* output_section,
		  typename elfcpp::Elf_types<size>::Elf_Off offset_in_output_section,
		  unsigned char* view,
		  typename elfcpp::Elf_types<size>::Elf_Addr view_address,
		  section_size_type view_size,
		  unsigned char* reloc_view,
		  section_size_type reloc_view_size)
{
  typedef gold::Default_classify_reloc<elfcpp::SHT_RELA, size, false>
    Classify_reloc;
  gold_assert(sh_type == elfcpp::SHT_RELA);

  gold::relocate_relocs<size, false, Classify_reloc>(
    relinfo,
    prelocs,
    reloc_count,
    output_section,
    offset_in_output_section,
    view,
    view_address,
    view_size,
    reloc_view,
    reloc_view_size);
}

  int64_t
  do_tls_offset_for_local(const Relobj*,
			  unsigned int,
			  Output_data_got_base *,
			  unsigned int,
			  uint64_t) const
  {
    return pm ? 32 : 2 * size / 8;
  }


  // Return the offset to use for the GOT_INDX'th got entry which is
  // for global tls symbol GSYM. Note that unlike `_bfd_e2k_elf_tpoff_base'
  // this function returns the value having an opposite sign. Moreover, here we
  // probably shouldn't care about subtraction of the output TLS section's VMA
  // since unlike LD the generic part of GOLD hasn't taken it into account when
  // calculating relocation for a TLS symbol prior to calling us (see
  // `Got_entry::write ()').
  // FIXME: take care of the output TLS section's alignment here. How are we
  // going to get access to it?
  int64_t
  do_tls_offset_for_global(Symbol* gsym,
			   Output_data_got_base *,
			   unsigned int got_idx,
			   uint64_t addend) const
  {
    unsigned int got_entry_size = pm ? 16 : (size / 8);
    if (gsym->type () != elfcpp::STT_TLS)
      gold_unreachable ();

    for (Got_type got_type = GOT_TYPE_TLS_IE;
	 got_type <= GOT_TYPE_TLS_GDREL;
	 got_type = Got_type (got_type + 1))
      {
	if (gsym->has_got_offset (got_type, addend)
	    && gsym->got_offset (got_type, addend) == got_idx * got_entry_size)
	  {
	    switch (got_type)
	      {
	      case GOT_TYPE_TLS_IE:
		return pm ? 32 : 2 * (size / 8);

	      case GOT_TYPE_TLS_GDREL:
		return 0;

	      default:
		gold_unreachable ();
	      }	
	  }
      }

    gold_unreachable ();
  }

  // Return the size of the GOT section.
  section_size_type
  got_size() const
  {
    gold_assert(this->got_ != NULL);
    return this->got_->data_size();
  }

  // Get the PLT section.
  Output_data_plt_e2k<size, pm> *
  plt_section() const
  {
    gold_assert(this->plt_ != NULL);
    return this->plt_;
  }


  // Return the PLT address to use for a global symbol.
  uint64_t
  do_plt_address_for_global(const Symbol* gsym) const
  { return this->plt_section()->address_for_global(gsym); }

protected:

  Object*
  do_make_elf_object(
		     const std::string& name,
		     Input_file* input_file,
		     off_t offset,
		     const elfcpp::Ehdr<size, false>& ehdr);


  void
  do_adjust_elf_header(unsigned char *view, int)
  {
    elfcpp::Ehdr_write<size, /* big_endian ==  */ false> oehdr(view);

    /* Stupidly mark the output ELF as intended for elbrus-v5 with
       EF_E2K_INCOMPAT flag set for the sake of compatibility with
       e2k-linux-gcc for elbrus-8c2.  */
    oehdr.put_e_flags((pm ? elfcpp::EF_E2K_PM : 0) | machine << 24);
  }

  void
  do_function_location(Symbol_location*) const
  { }

private:

  bool has_got_section() const
  { return this->got_ != NULL; }

  // Get the GOT section, creating it if necessary
  Output_data_got<pm ? 128 : size, false>*
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

  Output_data_plt_e2k<size, pm> *
  make_data_plt(Layout* layout, Output_data_got_plt_e2k<size, pm> *got_plt)
  {
    return new Output_data_plt_e2k<size, pm> (layout, got_plt);
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

  // Get the dynamic reloc section, creating it if necessary.
  Reloc_section*
  rela_dyn_section(Layout*);

  // Information about this specific target which we pass to the
  // general Target structure.
  static const Target::Target_info e2k_info;

  // The types of GOT entries needed for this platform.
  enum Got_type
  {
    GOT_TYPE_STANDARD = 0,      // GOT entry for a regular symbol
    GOT_TYPE_TLS_IE = 1,        // GOT entry for TLS IE model
    GOT_TYPE_TLS_GDREL = 2,	// GOT entry for REL in TLS GD model
    GOT_TYPE_TLS_GDMOD = 3,	// GOT entry for MOD in TLS GD model
  };

  // The GOT section.
  Output_data_got<pm ? 128 : size, false>* got_;

  // The PLT section.
  Output_data_plt_e2k<size, pm> *plt_;

  // The GOT PLT section.
  Output_data_got_plt_e2k<size, pm> *got_plt_;

  // The dynamic reloc section.
  Reloc_section* rela_dyn_;

  unsigned int tls_gdmod_got_offset_;

  unsigned char machine;
};

template<>
const Target::Target_info Target_e2k<32, false>::e2k_info =
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
const Target::Target_info Target_e2k<64, false>::e2k_info =
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

template<>
const Target::Target_info Target_e2k<64, true>::e2k_info =
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
  "/lib128/ld-linux.so.2",	// dynamic_linker
  0x00010000,			// default_text_segment_address
  64 * 1024,			// abi_pagesize (overridable by -z max-page-size)
  4 * 1024,			// common_pagesize (overridable by -z common-page-size)
  true,				// isolate_execinstr
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

    // Zero out ALS.src1 bits. Don't We zero too many bits in fact? It would
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
    // turns out to be negative. Can't We use an unsigned type when performing
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
  pc32(unsigned char* view,
       const Sized_relobj_file<size, false>* object,
       const Symbol_value<size>* psymval,
       typename elfcpp::Elf_types<size>::Elf_Addr addend,
       typename elfcpp::Elf_types<size>::Elf_Addr address)
  {
    typedef typename elfcpp::Swap<32, false>::Valtype Valtype;
    Valtype reloc = psymval->value(object, addend) - address;

    elfcpp::Swap<32, false>::writeval(view, reloc);
  }

  static void
  pc_lit64(unsigned char* view,
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

template<int size, bool pm>
Object*
Target_e2k<size, pm>::do_make_elf_object(
    const std::string& name,
    Input_file* input_file,
    off_t offset,
    const elfcpp::Ehdr<size, false>& ehdr)
{
  unsigned char mach = (ehdr.get_e_flags () >> 24) & 255;

  if (machine <= mach)
    machine = mach;

  return Target::do_make_elf_object (name, input_file, offset, ehdr);
}

template<int size, bool pm>
Output_data_got<pm ? 128 : size, false>*
Target_e2k<size, pm>::got_section(Symbol_table* symtab,
                              Layout* layout)
{
  if (this->got_ == NULL)
    {
      /* Whereas the ENTRY_SIZE should contain the value in BYTES, the SIZE
	 template argument is expressed in BITS.  */
      int entry_size = pm ? 16 : size / 8;
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

      this->got_ = new Output_data_got<pm ? 128 : size, false>();
      layout->add_output_section_data(".got", elfcpp::SHT_PROGBITS,
				      (elfcpp::SHF_ALLOC
				       | elfcpp::SHF_WRITE),
				      this->got_, got_order, true);

      this->got_plt_ = new Output_data_got_plt_e2k<size, pm> (layout);
      layout->add_output_section_data(".got.plt", elfcpp::SHT_PROGBITS,
                                      (elfcpp::SHF_ALLOC | elfcpp::SHF_WRITE),
                                      this->got_plt_, got_plt_order,
                                      is_got_plt_relro);

      // The first three entries are reserved for the link-time address of the
      // `.dynamic' section (filled in by ld) and runtime addresses of the link
      // map and `_dl_fixup ()' (initialized by ld.so).
      this->got_plt_->set_current_data_size(3 * entry_size);

      if (!is_got_plt_relro)
        {
          // These entries can go into the relro segment.
          layout->increase_relro(3 * entry_size);
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

template<int size, bool pm>
typename Target_e2k<size, pm>::Reloc_section*
Target_e2k<size, pm>::rela_dyn_section(Layout* layout)
{
  if (this->rela_dyn_ == NULL)
    {
      gold_assert(layout != NULL);
      this->rela_dyn_ = new Reloc_section(parameters->options().combreloc());
      layout->add_output_section_data(".rela.dyn", elfcpp::SHT_RELA,
				      elfcpp::SHF_ALLOC, this->rela_dyn_,
				      ORDER_DYNAMIC_RELOCS, false);
    }
  return this->rela_dyn_;
}

// Create the PLT section
template<int size, bool pm>
void
Target_e2k<size, pm>::make_plt_section(Symbol_table* symtab, Layout* layout)
{
  if (this->plt_ == NULL)
    {
      // Create the GOT sections first.
      this->got_section(symtab, layout);

      this->plt_ = this->make_data_plt(layout, this->got_plt_);

      layout->add_output_section_data(".plt", elfcpp::SHT_PROGBITS,
				      (elfcpp::SHF_ALLOC
				       | elfcpp::SHF_EXECINSTR),
				      this->plt_, ORDER_PLT, false);
    }
}

// Create a PLT entry for a global symbol
template<int size, bool pm>
void
Target_e2k<size, pm>::make_plt_entry(Symbol_table* symtab, Layout* layout,
				     Symbol* gsym)
{
  if (gsym->has_plt_offset())
    return;

  if (this->plt_ == NULL)
    this->make_plt_section(symtab, layout);

  this->plt_->add_entry(symtab, layout, gsym);
}

// Report an unsupported relocation against a local symbol.
template<int size, bool pm>
void
Target_e2k<size, pm>::Scan::unsupported_reloc_local(
                        Sized_relobj_file<size, false>* object,
                        unsigned int r_type)
{
  gold_error(_("%s: unsupported reloc %u against local symbol"),
	     object->name().c_str(), r_type);
}



// Scan a relocation for a local symbol.
template<int size, bool pm>
void
Target_e2k<size, pm>::Scan::local(
                        Symbol_table* symtab,
                        Layout* layout,
                        Target_e2k* target,
                        Sized_relobj_file<size, false>* object,
                        unsigned int data_shndx,
                        Output_section *output_section,
                        const elfcpp::Rela<size, false>& rela,
                        unsigned int r_type,
                        const elfcpp::Sym<size, false>&,
                        bool)
{
  switch (r_type)
    {
    case elfcpp::R_E2K_32_PC:
    case elfcpp::R_E2K_64_PC_LIT:
      /* PC-like relocations against local symbols should certainly be resoved
	 at link-time: their dynamic variants are NOT supported by ld.so and
	 shouldn't, therefore, emerge.  */
      break;

    case elfcpp::R_E2K_32_ABS:
    case elfcpp::R_E2K_64_ABS:
    case elfcpp::R_E2K_64_ABS_LIT:
      if (!pm
	  && parameters->options().output_is_position_independent())
	{
	  Reloc_section* rela_dyn = target->rela_dyn_section (layout);
	  unsigned int r_sym = elfcpp::elf_r_sym<size>(rela.get_r_info());
	  rela_dyn->add_local_relative (object, r_sym,
					(size == 32 /* Is this test appropriate for PM?  */
					 ? elfcpp::R_E2K_32_RELATIVE
					 : elfcpp::R_E2K_64_RELATIVE),
					output_section, data_shndx,
					rela.get_r_offset(),
					rela.get_r_addend (),
					false);
	}
      break;

    case elfcpp::R_E2K_AP:
    case elfcpp::R_E2K_PL:
      {
	  Reloc_section* rela_dyn = target->rela_dyn_section (layout);
	  unsigned int r_sym = elfcpp::elf_r_sym<size>(rela.get_r_info());
	  rela_dyn->add_local_relative (object, r_sym,
					r_type,
					output_section, data_shndx,
					rela.get_r_offset(),
					0, // This will be taken into account in relocate(): rela.get_r_addend (),
					false);
	}

      break;

    case elfcpp::R_E2K_TLS_IE:
    case elfcpp::R_E2K_TLS_GDMOD:
    case elfcpp::R_E2K_TLS_GDREL:
      {
	Got_type gtype = (r_type == elfcpp::R_E2K_TLS_IE
			  ? GOT_TYPE_TLS_IE
			  : (r_type == elfcpp::R_E2K_TLS_GDMOD
			     ? GOT_TYPE_TLS_GDMOD
			     : GOT_TYPE_TLS_GDREL));
        Output_data_got<pm ? 128 : size, false>* got;
        unsigned int r_sym = elfcpp::elf_r_sym<size>(rela.get_r_info());
        got = target->got_section(symtab, layout);

	if (! parameters->options().shared() || r_type != elfcpp::R_E2K_TLS_IE)
	  got->add_local_tls(object, r_sym, gtype);
	else
	  got->add_local_with_rel(object, r_sym, gtype,
				  target->rela_dyn_section(layout),
				  ((size == 32 || pm)
				   ? elfcpp::R_E2K_TLS_TPOFF32
				   : elfcpp::R_E2K_TLS_TPOFF64));
      }
      break;

    case elfcpp::R_E2K_32_TLS_LE:
    case elfcpp::R_E2K_64_TLS_LE:
    case elfcpp::R_E2K_GOT:
    case elfcpp::R_E2K_GOTOFF:
    case elfcpp::R_E2K_64_GOTOFF:
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
template<int size, bool pm>
void
Target_e2k<size, pm>::Scan::unsupported_reloc_global(
                        Sized_relobj_file<size, false>* object,
                        unsigned int r_type,
                        Symbol* gsym)
{
  gold_error(_("%s: unsupported reloc %u against global symbol %s"),
             object->name().c_str(), r_type, gsym->demangled_name().c_str());
}

// Scan a relocation for a global symbol.
template<int size, bool pm>
void
Target_e2k<size, pm>::Scan::global(
                        Symbol_table* symtab,
                        Layout* layout,
                        Target_e2k* target,
                        Sized_relobj_file<size, false> *object,
                        unsigned int data_shndx,
                        Output_section *output_section,
                        const elfcpp::Rela<size, false> &reloc,
                        unsigned int r_type,
                        Symbol* gsym)
{
  if (!target->has_got_section()
      && strcmp (gsym->name(), "_GLOBAL_OFFSET_TABLE_") == 0)
    target->got_section(symtab, layout);

  switch (r_type)
    {
    case elfcpp::R_E2K_32_PC:
    case elfcpp::R_E2K_64_PC_LIT:
      /* PC-like relocations should typically be resoved at link-time even
	 against a global symbol: their dynamic variants are NOT supported
	 by ld.so and shouldn't, therefore, emerge.  */
      break;

    case elfcpp::R_E2K_32_ABS:
    case elfcpp::R_E2K_64_ABS:
    case elfcpp::R_E2K_64_ABS_LIT:
      if (! pm
	  && ! gsym->final_value_is_known ())
	{
	  Reloc_section* rela_dyn = target->rela_dyn_section (layout);
	  unsigned int dyn_r_type;

	  /* Stupidly take -static-pie executables into account this way
	     for now. This will prevent inappropriate R_E2K_*ABS*
	     relocations from emerging in them.  */
	  if (parameters->options().is_static())
	    {
	      dyn_r_type = (r_type == elfcpp::R_E2K_32_ABS
			    ? elfcpp::R_E2K_32_RELATIVE
			    : (r_type == elfcpp::R_E2K_64_ABS
			       ? elfcpp::R_E2K_64_RELATIVE
			       : elfcpp::R_E2K_64_RELATIVE_LIT));
	      rela_dyn->add_global_relative (gsym, dyn_r_type, output_section, object,
					     data_shndx, reloc.get_r_offset (),
					     reloc.get_r_addend (), false);
	    }
	  else
	    {
	      dyn_r_type = r_type;
	      rela_dyn->add_global (gsym, dyn_r_type, output_section, object,
				    data_shndx, reloc.get_r_offset (),
				    reloc.get_r_addend ());
	    }
	}
      break;

    case elfcpp::R_E2K_AP:
    case elfcpp::R_E2K_PL:
      if (! gsym->final_value_is_known ())
	{
	  Reloc_section* rela_dyn = target->rela_dyn_section (layout);
	  unsigned int dyn_r_type = r_type;
	  rela_dyn->add_global (gsym, dyn_r_type, output_section, object,
				data_shndx, reloc.get_r_offset (),
				reloc.get_r_addend ());
	}
      break;

    case elfcpp::R_E2K_TLS_GDMOD:
      if (target->tls_gdmod_got_offset_ == -1U)
	{
	  Output_data_got<pm ? 128 : size, false>* got;
	  got = target->got_section(symtab, layout);
	  target->tls_gdmod_got_offset_ = got->add_constant (1);
	}
      break;

    case elfcpp::R_E2K_TLS_IE:
    case elfcpp::R_E2K_TLS_GDREL:
      {
	Got_type gtype = (r_type == elfcpp::R_E2K_TLS_IE
			  ? GOT_TYPE_TLS_IE
			  : GOT_TYPE_TLS_GDREL);
        Output_data_got<pm ? 128 : size, false>* got;
        got = target->got_section(symtab, layout);

	if (gsym->final_value_is_known ()
	    || parameters->options().is_static ())
	  got->add_global_tls(gsym, gtype);
	else
	  {
	    Reloc_section* rela_dyn = target->rela_dyn_section(layout);
	    got->add_global_with_rel (gsym, gtype, rela_dyn,
				      (gtype == GOT_TYPE_TLS_IE
				       ? ((size == 32 || pm)
					  ? elfcpp::R_E2K_TLS_TPOFF32
					  : elfcpp::R_E2K_TLS_TPOFF64)
				       : ((size == 32 || pm)
					  ? elfcpp::R_E2K_TLS_32_DTPREL
					  : elfcpp::R_E2K_TLS_64_DTPREL)));
	  }
      }
      break;

    case elfcpp::R_E2K_32_TLS_LE:
    case elfcpp::R_E2K_64_TLS_LE:
    case elfcpp::R_E2K_TLS_32_DTPREL:
    case elfcpp::R_E2K_TLS_64_DTPREL:
      break;

    case elfcpp::R_E2K_GOT:
      {
        Output_data_got<pm ? 128 : size, false>* got;
        got = target->got_section(symtab, layout);

	if (gsym->final_value_is_known ())
	  got->add_global (gsym, GOT_TYPE_STANDARD);
	else
	  {
	    // If this symbol is not fully resolved, we need to add a
	    // GOT entry with a dynamic relocation.
	    Reloc_section* rela_dyn = target->rela_dyn_section(layout);
	    unsigned int dyn_r_type;

	    if (parameters->options().is_static())
	      {
		dyn_r_type = size == 32 ? elfcpp::R_E2K_32_RELATIVE : elfcpp::R_E2K_64_RELATIVE;
		got->add_global_with_rel (gsym, GOT_TYPE_STANDARD, rela_dyn,
					  dyn_r_type, 0, true, true);
	      }
	    else
	      {
		dyn_r_type = size == 32 ? elfcpp::R_E2K_32_ABS : elfcpp::R_E2K_64_ABS;
		/* How does the section containing
		   "_ZZNSs12_S_constructIPKcEEPcT_S3_RKSaIcESt20forward_iterator_tagEs"
		   manage to remain unreferenced (see is_section_garbage ()) if
		   a dynamic relocation against this (dynamic) symbol is created
		   here? May it be that the section referring to it turns out
		   to be "garbage" too? Even if so, the dynamic symbol (even if
		   it was forced to become dynamic because of the dynamic
		   relocation) could be referenced from the outside, which
		   makes the removal of the containing section doubtful.
		   FIXME(?): find out if it's possible to do without creation
		   of such "forced" dynamic symbols.  */
		got->add_global_with_rel (gsym, GOT_TYPE_STANDARD, rela_dyn, dyn_r_type);
	      }
	  }
      }
      break;

    case elfcpp::R_E2K_AP_GOT:
    case elfcpp::R_E2K_PL_GOT:
      if (pm)
	{
	  Output_data_got<pm ? 128 : size, false>* got;
	  got = target->got_section(symtab, layout);
	  Reloc_section* rela_dyn = target->rela_dyn_section(layout);
	  // We need Sized_symbol for symsize (). But is it always OK to get it
	  // this way?
	  const Sized_symbol<size> *sym = static_cast<const Sized_symbol<size>*>(gsym);

	  got->add_global_with_rel_and_cst (gsym, GOT_TYPE_STANDARD, rela_dyn,
					    (r_type == elfcpp::R_E2K_AP_GOT
					     ? elfcpp::R_E2K_AP : elfcpp::R_E2K_PL),
					    0,
					    // Stupidly make use of a symbolless relative
					    // relocation in -static-pie case only for now.
					    // This prevents us from creating a defective
					    // relative relocation against a dynamic symbol
					    // undefined in the present dynamic object.
					    parameters->options().is_static() ? true : false,
					    parameters->options().is_static() ? true : false,
					    // No placeholder within the section is required for
					    // AP.base as it's evaluated by ld.so based on the
					    // dynamic symbol's value or the relative relocation's
					    // R_ADDEND.
					    0,
					    // No idea how AP.curptr in GOT (encoded
					    // in the lower 32 bits) could turn out
					    // to be non-zero.
					    // Extract the SIZE from the input(?)
					    // symbol and put it in place of the
					    // eventual AP.size as there will be
					    // no other source to get it from when
					    // resolving a "relative" R_E2K_AP against
					    // this GOT entry.
					    r_type == elfcpp::R_E2K_AP_GOT ? (sym->symsize() << 32) : 0);
	}
      break;

    case elfcpp::R_E2K_GOTOFF:
    case elfcpp::R_E2K_64_GOTOFF:
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

template <int size, bool pm>
void
Target_e2k<size, pm>::scan_relocs(
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
  typedef Target_e2k<size, pm> E2k;
  typedef typename Target_e2k<size, pm>::Scan Scan;

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

template<int size, bool pm>
bool
Target_e2k<size, pm>::Relocate::relocate(
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

  // Pick the value to use for symbols defined in shared objects.
  Symbol_value<size> symval;
  if (gsym != NULL
      && gsym->use_plt_offset(/*Scan::get_reference_flags(r_type)*/ r_type == elfcpp::R_E2K_DISP ? Symbol::FUNCTION_CALL : 0))
    {
      symval.set_output_value(target->plt_address_for_global(gsym));
      psymval = &symval;
    }

  switch (r_type)
    {
    case elfcpp::R_E2K_AP:
      // There's probably no point in writing anything out at location
      // R_E2K_AP is applied to.
      if (gsym == NULL)
	{
	  elfcpp::Swap<32, false>::writeval(view + 8, addend);
	  elfcpp::Swap<32, false>::writeval(view + 12, psymval->input_size ());
	}
      break;
    case elfcpp::R_E2K_PL:
      break;
    case elfcpp::R_E2K_64_ABS:
      Relocate_functions<size, false>::rela64(view, object, psymval, addend);
      break;
    case elfcpp::R_E2K_32_ABS:
      Relocate_functions<size, false>::rela32(view, object, psymval, addend);
      break;

    case elfcpp::R_E2K_64_ABS_LIT:
      Reloc::abs_lit(view, object, psymval, addend);
      break;

    case elfcpp::R_E2K_32_PC:
      Reloc::pc32(view, object, psymval, addend, address);
      break;

    case elfcpp::R_E2K_64_PC_LIT:
      Reloc::pc_lit64(view, object, psymval, addend, address);
      break;

    case elfcpp::R_E2K_TLS_IE:
    case elfcpp::R_E2K_TLS_GDMOD:
    case elfcpp::R_E2K_TLS_GDREL:
      {
        unsigned int got_offset;
	Got_type gtype = (r_type == elfcpp::R_E2K_TLS_IE
			  ? GOT_TYPE_TLS_IE
			  : (r_type == elfcpp::R_E2K_TLS_GDMOD
			     ? GOT_TYPE_TLS_GDMOD
			     : GOT_TYPE_TLS_GDREL));

	if (gtype == GOT_TYPE_TLS_GDMOD)
	  got_offset = target->tls_gdmod_got_offset_;
        else if (gsym != NULL)
          got_offset = gsym->got_offset(gtype);
        else
          {
            unsigned int r_sym = elfcpp::elf_r_sym<size>(rela.get_r_info());
            got_offset = object->local_got_offset(r_sym, gtype);
          }

	Relocate_functions<size,false>::rela32
	  (view,
	   (! pm
	    ? got_offset - target->got_size ()
	    : target->got_address () + got_offset), addend);
        }
      break;

    case elfcpp::R_E2K_32_TLS_LE:
      Relocate_functions<size, false>::rela32(view, object, psymval,
					      // May ADDEND be anything but 0
					      // in this context?
					      (addend
					       // This should roughly match the
					       // behaviour of e2k-linux-ld.bfd
					       // presumably without correctly
					       // taking into account the TLS
					       // section's alignment.
					       + (pm ? 32 : 2 * (size / 8))));
      break;
    case elfcpp::R_E2K_64_TLS_LE:
      Reloc::abs_lit(view, object, psymval,
		     // See my comments on ADDEND a few lines above.
		     (addend + (pm ? 32 : 2 * (size / 8))));
      break;

    case elfcpp::R_E2K_TLS_32_DTPREL:
      Relocate_functions<size, false>::rela32(view, object, psymval, addend);
      break;

    case elfcpp::R_E2K_TLS_64_DTPREL:
      Relocate_functions<size, false>::rela64(view, object, psymval, addend);
      break;

    case elfcpp::R_E2K_GOT:
      {
        unsigned int got_offset;
        got_offset = gsym->got_offset(GOT_TYPE_STANDARD);
        Relocate_functions<size,false>::rela32
	  (view, got_offset - target->got_size (), addend);
      }
      break;

    case elfcpp::R_E2K_AP_GOT:
    case elfcpp::R_E2K_PL_GOT:
      {
        unsigned int got_offset;
        got_offset = gsym->got_offset(GOT_TYPE_STANDARD);
        Relocate_functions<size,false>::rela32
	  (view, target->got_address() + got_offset, addend);
      }
      break;

    case elfcpp::R_E2K_GOTOFF:
      {
        unsigned int got_offset;
        got_offset = psymval->value(object, 0) - target->got_address ();
        Relocate_functions<size,false>::rela32
	  (view, got_offset - target->got_size (), addend);
      }
      break;

    case elfcpp::R_E2K_64_GOTOFF:
    case elfcpp::R_E2K_64_GOTOFF_LIT:
      {
        uint64_t got_offset;
        got_offset = (psymval->value(object, 0)
		      - (target->got_address () + target->got_size ())
		      + addend);

	if (r_type == elfcpp::R_E2K_64_GOTOFF_LIT)
	  got_offset = ((got_offset & 0xffffffff) << 32) | (got_offset >> 32);

	/* FIXME: what about ADDEND != 0 ? Shouldn't it be taken into account
	   during the evaluation of GOT_OFFSET and replaced with 0 here?  */
        Relocate_functions<size,false>::rela64
	  (view, got_offset, /* addend  */ 0);
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

// Finalize the sections.

template<int size, bool pm>
void
Target_e2k<size, pm>::do_finalize_sections(Layout* layout,
				       const Input_objects*,
				       Symbol_table* symtab)
{
  const Reloc_section* rela_plt = (this->plt_ == NULL
				   ? NULL
				   : this->plt_->rela_plt());

  layout->add_target_dynamic_tags (false, ! pm ? this->got_plt_ : NULL,
				   rela_plt, this->rela_dyn_, true, true, false);

  if (pm)
    {
      Output_data_dynamic* const odyn = layout->dynamic_data();
      if (odyn)
	{
	  odyn->add_constant(elfcpp::DT_PLTGOT, 0x0);
	  odyn->add_symbol(elfcpp::DT_E2K_PLTGOTSZ, symtab->lookup("_end"));
	  if (this->got_plt_ && this->got_plt_->output_section () != NULL)
	    odyn->add_section_address(elfcpp::DT_E2K_REAL_PLTGOT, this->got_plt_);
	}
    }

  if (rela_plt != NULL)
    {
      Output_data_dynamic* const odyn = layout->dynamic_data();
      odyn->add_constant(elfcpp::DT_E2K_LAZY_GOT,
			 /* The value is not important for our implementation
			    in fact.  */
			 0x0);
    }

  /* It's crucial that the buffer passed to Output_data_const_buffer () below
     is STATIC. Otherwise junk would be written to the output section later.  */
  static const unsigned getpl_code[] =
    {
      0x00005212, /* foo: nop 4  */
      0x80000000, /*  ipd 2  */
      0xf0000000, /*  return %ctpr3  */
      0x00000000,
      0x04000001, /* :  */
      0x63f08280, /*  getpl,0 %r2, %dr0  */
      0x00009012, /* :  */
      0xc0000c20, /*  ct %ctpr3  */
		  /*  ipd 3  */
      0x30000002, /*  wait trap = 0, ma_c = 0, fl_c = 0, ld_c = 0, st_c = 0, all_e = 1, all_c = 0  */
      0x00000000
    };

  if (pm
      && ! parameters->options().relocatable()
      && ! parameters->doing_static_link())
    {
      Output_section_data* posd = new Output_data_const_buffer
	((const unsigned char *) getpl_code, sizeof (getpl_code), 8, "** getpl");
      layout->add_output_section_data(".text.getpl", elfcpp::SHT_PROGBITS,
				      (elfcpp::SHF_ALLOC | elfcpp::SHF_EXECINSTR),
				      posd, ORDER_TEXT, false);

      Output_data_dynamic* const odyn = layout->dynamic_data();
      gold_assert (odyn != NULL);
      odyn->add_section_address (elfcpp::DT_E2K_INIT_GOT, posd);
      odyn->add_constant (elfcpp::DT_E2K_NO_SELFINIT, 0x1);
    }
}

// Relocate section data.

template<int size, bool pm>
void
Target_e2k<size, pm>::relocate_section(
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
  typedef Target_e2k<size, pm> E2k;
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

template<int size, bool pm>
class Target_selector_e2k : public Target_selector
{
public:
  Target_selector_e2k()
    : Target_selector(elfcpp::EM_MCST_ELBRUS, size, false,
                      (size == 64
		       ? (pm ? "elf64-e2k-pm" : "elf64-e2k")
		       : "elf32-e2k"),
                      (size == 64
		       ? (pm ? "elf64_e2k_pm" : "elf64_e2k")
		       : "elf32_e2k"))
  { }

  virtual Target*
  do_recognize(Input_file*, off_t, int, int, int, int flags)
  {
    if ((pm && (flags & elfcpp::EF_E2K_PM) == 0)
	|| (!pm && (flags & elfcpp::EF_E2K_PM) != 0))
      return NULL;

    return this->instantiate_target();
  }

  virtual Target*
  do_instantiate_target()
  { return new Target_e2k<size, pm>(); }
};

Target_selector_e2k<32, false> target_selector_e2k32;
Target_selector_e2k<64, false> target_selector_e2k64;
Target_selector_e2k<64, true> target_selector_e2k128;

} // End anonymous namespace.
