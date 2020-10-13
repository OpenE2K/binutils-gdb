# At present I'd prefer to have `OUTPUT_ARCH(e2k:pm)' rather than just
# `OUTPUT_ARCH (e2k)' inside the corresponding LD script (see elf.sc).
MACHINE=pm
ENABLE_BUG_89922=yes
OUTPUT_FORMAT="elf32-e2k-pm"

# Avoid placing read-only data sections into the code segment in E2K
# Protected Mode this way:
SEPARATE_CODE=yes

# Ensure that `/{,usr/,...}lib128' libraries are inserted at the start
# of SEARCH_DIRs.
LIBPATH_SUFFIX=128

. ${srcdir}/emulparams/elf_e2k.sh

# Unlike ordinary modes I'd prefer a shared library's text segment to start
# from a non-zero address since zero link-time relocation values are currently
# used to distinguish weak undefined symbols when generating `__selfinit ()' in
# my PM BFD backend.
SHLIB_TEXT_START_ADDR=$TEXT_START_ADDR

# Taking into account that 'SEGMENT_SIZE == MAXPAGESIZE' by default this
# ensures that RO segment has a suitable alignment for placing ELF and Program
# Headers in the very beginning of it. Sufficient space for them is allocated
# in ld/scripttempl/elf.sc by means of SIZEOF_HEADERS.
RODATA_ADDR="ALIGN(${SEGMENT_SIZE})"
SHLIB_RODATA_ADDR=$RODATA_ADDR

TEXT_START_SYMBOLS="
  PROVIDE_HIDDEN (__selfinit = .);
  *(.text.selfinit)"
