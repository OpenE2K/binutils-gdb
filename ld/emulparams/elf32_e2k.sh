# At present I'd prefer to have `OUTPUT_ARCH(e2k:32)' rather than just
# `OUTPUT_ARCH (e2k)' inside the corresponding LD script (see elf.sc).
MACHINE=32
OUTPUT_FORMAT="elf32-e2k"

# This suffix is appended to various paths when generating SEARCH_DIRs. Keep in
# mind that it is appended even in case when USE_LIBPATH is not set to yes (e.g.
# to paths coming from TOOL_DIR when building a cross-ld). The failure to set it
# turned out to be a reason for Bug #70607 (a duplicate of Bug #45284 for
# up-to-date binutils).
LIBPATH_SUFFIX=32


source_sh ${srcdir}/emulparams/elf_e2k.sh
