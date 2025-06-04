#ifndef CONFIG_NM_E2K_GOLANG_H
#define CONFIG_NM_E2K_GOLANG_H

typedef unsigned long long e2k_golang_gregset_t[20];

#define GDB_GREGSET_T  e2k_golang_gregset_t
#define GDB_FPREGSET_T elf_fpregset_t

#endif /* CONFIG_NM_E2K_GOLANG_H */
