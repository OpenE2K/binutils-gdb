/* Handle E2k Protected Mode style shared libraries for GDB, the GNU Debugger.

   Copyright (C) 2000, 2004, 2006, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef SOLIB_PM_H
#define SOLIB_PM_H

struct link_map_offsets
{
  /* Offset of my_r_debug.r_map.  */
  int r_map_offset;

  /* Offset of my_r_debug.r_brk.  */
  int r_brk_offset;

  /* Size of struct link_map (or equivalent), or at least enough of it
     to be able to obtain the fields below.  */
  int link_map_size;

  /* Offset to `l_data_addr' field in `struct my_link_map'.  */
  int l_data_addr_offset;

  /* Offset to `l_code_addr' field in `struct my_link_map'.  */
  int l_code_addr_offset;

  /* Offset to `l_name' field in `struct my_link_map'.  */
  int l_name_offset;

  /* Offset to `l_next' field in `struct my_link_map'.  */
  int l_next_offset;

  /* Offset to `l_prev' field in `struct my_link_map'.  */
  int l_prev_offset;
};

extern void set_solib_pm_ops (struct gdbarch *gdbarch);

#endif /* solib-pm.h */
