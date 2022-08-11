# Prevent e2k_set_output_arch () in e2kelf.em from referencing 32 and Protected
# Mode target vectors which are not supported for KPDA meanwhile.
KPDA=1
source_sh ${srcdir}/emulparams/elf64_e2k.sh

# Ensure that a KPDA-specific BFD target is used.
OUTPUT_FORMAT="elf64-e2k-kpda"
