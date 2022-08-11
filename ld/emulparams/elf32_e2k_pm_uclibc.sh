source_sh ${srcdir}/emulparams/elf32_e2k_pm.sh
E2K_UCLIBC=1
# Override BFD target name provided by the above script.
OUTPUT_FORMAT="elf32-e2k-pm-uclibc"
