#define MYHOWTO(C, R,S,B, P, BI, O, SF, NAME, INPLACE, MASKSRC, MASKDST, PC) \
    [C] = HOWTO(C, R,S,B, P, BI, O, SF, NAME, INPLACE, MASKSRC, MASKDST, PC)

  MYHOWTO (R_ELCORE_NONE,               /* type */
           0,           		/* rightshift */
           2,                   	/* size (0 = byte, 1 = short, 2 = long) */
           32,                          /* bitsize */
           FALSE,                       /* pc_relative */
           0,                           /* bitpos */
           complain_overflow_dont,      /* complain_on_overflow */
           bfd_elf_generic_reloc,       /* special_function */
           "R_ELCORE_NONE",             /* name */
           FALSE,                       /* partial_inplace */
           0,                           /* src_mask */
           0,                           /* dst_mask */
           FALSE),                      /* pcrel_offset */

  /* relocation for I5 */
  MYHOWTO (R_ELCORE_I5,			/* type */
           2,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           5,			/* bitsize */
           FALSE,			/* pc_relative */
           27,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I5",		/* name */
           FALSE,			/* partial_inplace */
           0xf8000000,			/* src_mask */
           0xf8000000,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  /* relocation for I5 */
  MYHOWTO (R_ELCORE_I5_FAKE,    /* type */
           0,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           5,			/* bitsize */
           FALSE,			/* pc_relative */
           27,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I5_FAKE",		/* name */
           FALSE,			/* partial_inplace */
           0xf8000000,			/* src_mask */
           0xf8000000,			/* dst_mask */
           FALSE),		/* pcrel_offset */


  MYHOWTO (R_ELCORE_I16,			/* type */
           2,			/* rightshift */
           1,			/* size (0 = byte, 1 = short, 2 = long) */
           0,			/* bitsize */
           FALSE,			/* pc_relative */
           0,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I16",		/* name */
           FALSE,			/* partial_inplace */
           0x0000ffff,			/* src_mask */
           0x0000ffff,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_I16_FAKE,			/* type */
           0,			/* rightshift */
           1,			/* size (0 = byte, 1 = short, 2 = long) */
           0,			/* bitsize */
           FALSE,			/* pc_relative */
           0,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I16_FAKE",		/* name */
           FALSE,			/* partial_inplace */
           0x0000ffff,			/* src_mask */
           0x0000ffff,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_I16PC,			/* type */
           2,			/* rightshift */
           1,			/* size (0 = byte, 1 = short, 2 = long) */
           0,			/* bitsize */
           TRUE,			/* pc_relative */
           0,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I16PC",		/* name */
           FALSE,			/* partial_inplace */
           0x0000ffff,			/* src_mask */
           0x0000ffff,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_I16PC_FAKE,			/* type */
           0,			/* rightshift */
           1,			/* size (0 = byte, 1 = short, 2 = long) */
           0,			/* bitsize */
           TRUE,			/* pc_relative */
           0,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I16PC_FAKE",	/* name */
           FALSE,			/* partial_inplace */
           0x0000ffff,			/* src_mask */
           0x0000ffff,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_S16,			/* type */
           2,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           16,			/* bitsize */
           FALSE,			/* pc_relative */
           11,			/* bitpos */
           complain_overflow_dont, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_S16",		/* name */
           FALSE,			/* partial_inplace */
           0x07fff800,			/* src_mask */
           0x07fff800,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_S16_FAKE,			/* type */
           0,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           16,			/* bitsize */
           FALSE,			/* pc_relative */
           11,			/* bitpos */
           complain_overflow_dont, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_S16_FAKE",		/* name */
           FALSE,			/* partial_inplace */
           0x07fff800,			/* src_mask */
           0x07fff800,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_S16PC,			/* type */
           2,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           16,			/* bitsize */
           TRUE,			/* pc_relative */
           11,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_S16PC",		/* name */
           FALSE,			/* partial_inplace */
           0x07fff800,			/* src_mask */
           0x07fff800,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  MYHOWTO (R_ELCORE_S16PC_FAKE,			/* type */
           0,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           16,			/* bitsize */
           TRUE,			/* pc_relative */
           11,			/* bitpos */
           complain_overflow_bitfield, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_S16PC_FAKE",	/* name */
           FALSE,			/* partial_inplace */
           0x07fff800,			/* src_mask */
           0x07fff800,			/* dst_mask */
           FALSE),		/* pcrel_offset */

  /* A standard 32 bit relocation.  */
  MYHOWTO (R_ELCORE_I32,			/* type */
           2,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           32,			/* bitsize */
           FALSE,			/* pc_relative */
           0,			/* bitpos */
           complain_overflow_dont, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I32",		/* name */
           FALSE,			/* partial_inplace */
           0xffffffff,			/* src_mask */
           0xffffffff,			/* dst_mask */
           FALSE),                /* pcrel_offset */

 MYHOWTO (R_ELCORE_I32_FAKE,			/* type */
           0,			/* rightshift */
           2,			/* size (0 = byte, 1 = short, 2 = long) */
           32,			/* bitsize */
           FALSE,			/* pc_relative */
           0,			/* bitpos */
           complain_overflow_dont, /* complain_on_overflow */
           bfd_elf_generic_reloc,			/* special_function */
           "R_ELCORE_I32_FAKE",		/* name */
           FALSE,			/* partial_inplace */
           0xffffffff,			/* src_mask */
           0xffffffff,			/* dst_mask */
           FALSE),		/* pcrel_offset */

#undef MYHOWTO
