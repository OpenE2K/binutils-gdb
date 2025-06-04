#ifndef E2K_GOLANG_TDEP_H
#define E2K_GOLANG_TDEP_H 1

/* Register window consists of 12 %rX registers and 8 %b[Y] ones which are
   intentionally NOT recognized as `%r{Y+12}'s for now. GOLANG is aware of
   %r{0,...,7}, %SP <=> %r8,  %SB <=> %r9 and %G <=> %r10, other ones,
   including `%b[Y]'s, are used in an opaque way. There is also a %pc
   register.  */
enum
{
 E2K_GOLANG_R0_REGNUM = 0,
 E2K_GOLANG_R11_REGNUM = 11,
 E2K_GOLANG_B0_REGNUM = 12,
 E2K_GOLANG_B7_REGNUM = 19,
 E2K_GOLANG_PC_REGNUM = 20,
 NUM_E2K_GOLANG_RAW_REGS = E2K_GOLANG_PC_REGNUM + 1,
};

/* Believe that there are no pseudo registers FOR NOW.  */
#define NUM_E2K_GOLANG_PSEUDO_REGS	(0)

extern const struct target_desc *tdesc_e2k_golang;

#endif /* E2K_GOLANG_TDEP_H  */
