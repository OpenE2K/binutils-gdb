source_sh ${srcdir}/emulparams/elf64_e2k.sh
E2K_UCLIBC=1
# Override BFD target name provided by the above script.
OUTPUT_FORMAT="elf64-e2k-uclibc"
