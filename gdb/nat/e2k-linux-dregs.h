#ifndef E2K_LINUX_DREGS_H
#define E2K_LINUX_DREGS_H

extern unsigned long e2k_linux_dr_get_ddbsr (void);
extern CORE_ADDR e2k_linux_dr_get_ddbar (int regnum);

extern void e2k_linux_update_debug_registers (struct lwp_info *lwp);

#endif /* E2K_LINUX_DREGS_H  */
