# If you change this file, please also look at files which source this one:
# elf32_sparc_vxworks.sh

SCRIPT_NAME=elf
OUTPUT_FORMAT="elf32-sparc"
NO_REL_RELOCS=yes
TEXT_START_ADDR=0x10000
MAXPAGESIZE="CONSTANT (MAXPAGESIZE)"
COMMONPAGESIZE="CONSTANT (COMMONPAGESIZE)"
ALIGNMENT=8
ARCH=sparc
MACHINE=
TEMPLATE_NAME=elf
EXTRA_EM_FILE=sparcelf
DATA_PLT=
GENERATE_SHLIB_SCRIPT=yes
GENERATE_PIE_SCRIPT=yes
NOP=0x01000000
NO_SMALL_DATA=yes

# Configurations with `--host=sparc-linux' and `--target=sparc-linux-elf'
# (see Bug #60990 for motivations which make us configure binutils this way)
# should be considered native so that `/usr/local/lib /lib /usr/lib' can find
# their way to SEARCH_DIR (". . .") as it happens when both
# `--{host,target}=sparc-linux'. The absence of the aforementioned paths in
# SEARCH_DIR (". . .") led to Bug #65304.
# Fix this problem in the most primitive way: if the host seems to be Sparc of
# any kind, treat this configuration as native.
case "$host" in
    sparc*-*)
        NATIVE=yes
        ;;
esac

# Support EIR linkage. This variable is used in `ldelf.c' to emit the code
# which prevents us from customizing `__ehdr_start' when linking EIR.
SUPPORT_EIR=yes

# On modern Sparc64 Debian sid 32-bit glibc is installed into `{,/usr}/lib32'.
# Ensure that `sparc64-linux-ld' is capable of finding it without the help of
# `-L/lib/../lib32 -L/usr/lib/../lib32' options which are explicitly passed to
# it by GCC on such systems as I'm reluctant to replicate this idiotic
# behaviour.
if [ "x${enable_debian_multiarch}" = "xyes" ]; then
    LIBPATH_SUFFIX=32
fi
