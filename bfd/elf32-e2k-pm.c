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

/* The only macro that should be defined prior to inclusion of
   elf32-e2k.c so as to prevent it from including elf32-target.h
   before we redefine all other macros of interest.  */
#define TARGET_LITTLE_NAME		"elf32-e2k-pm"
#include "elf32-e2k.c"

#undef TARGET_LITTLE_SYM
#define TARGET_LITTLE_SYM		e2k_pm_elf32_vec

#include "elfxx-e2k-pm.h"

#include "elf32-target.h"
