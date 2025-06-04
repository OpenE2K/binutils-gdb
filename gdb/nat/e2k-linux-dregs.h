/* Copyright (c) 2009-2025 AO MCST.
   Copyright (C) 1991-2025 Free Software Foundation, Inc.
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this program; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef E2K_LINUX_DREGS_H
#define E2K_LINUX_DREGS_H

extern unsigned long e2k_linux_dr_get_ddbsr (void);
extern CORE_ADDR e2k_linux_dr_get_ddbar (int regnum);

extern void e2k_linux_update_debug_registers (struct lwp_info *lwp);

#endif /* E2K_LINUX_DREGS_H  */
