SCRIPT_NAME=elf
NO_REL_RELOCS=yes
TEXT_START_ADDR="MAX (0x10000, CONSTANT (MAXPAGESIZE))"
MAXPAGESIZE="CONSTANT (MAXPAGESIZE)"
COMMONPAGESIZE="CONSTANT (COMMONPAGESIZE)"
ALIGNMENT=8
ARCH=e2k
TEMPLATE_NAME=elf32
EXTRA_EM_FILE=e2kelf
GENERATE_SHLIB_SCRIPT=yes
GENERATE_PIE_SCRIPT=yes
NO_SMALL_DATA=yes

# I'd like '-rpath' option to take effect when performing the link
# (see the implementation of after_open () in elf32.em).
# Am not I going to break anything . . . ?

# . . . as a consequence directories coming from the NATIVE_LIB_DIRS parameter
# of 'genscripts.sh' (i.e. "/usr/local/lib /lib /usr/lib") are included in
# SEARCH_DIRs of cross-ld for which USE_LIBPATH shouldn't be normally set . . .
# What was the point for treating '-rpath' specially in case of cross-ld? Can
# I stop setting 'USE_LIBPATH' here? In case you do, don't forget to add
# 'elf32_e2k' to 'EMULATION_LIBPATH' in 'genscripts.sh' by setting
# 'targ_extra_libpath=elf32_e2k' in ld/configure.tgt . Otherwise it won't be
# set when generating 'elf32_e2k' emulation for native LD and it'll never get
# NATIVE_LIB_DIRS . . .
USE_LIBPATH=yes

# In non-protected mode we need a special `place_orphan'
# method to group dsp sections together without a script.
LDEMUL_PLACE_ORPHAN=${EMULATION_NAME}_place_orphan


# In non-protected mode we need a special `after_allocation'
# method to correct DSP sections' VMAs.
LDEMUL_AFTER_ALLOCATION=${EMULATION_NAME}_after_allocation;


# Support EIR linkage. This variable is used in `elf32.em' to emit the code
# which prevents us from customizing `__ehdr_start' when linking EIR.
SUPPORT_EIR=yes

# Delay checking ELF relocations until opening all input files
CHECK_RELOCS_AFTER_OPEN_INPUT=yes
