/* Copyright (C) 1991-2023 Free Software Foundation, Inc.

   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _MACH_I386_SYSDEP_H
#define _MACH_I386_SYSDEP_H 1

#include <sysdeps/mach/x86/sysdep.h>

#define RETURN_TO(sp, pc, retval) \
  asm volatile ("movl %0, %%esp; jmp %*%1 # %2" \
		: : "g" (sp), "r" (pc), "a" (retval))

/* This should be rearranged, but at the moment this file provides
   the most useful definitions for assembler syntax details.  */
#undef ENTRY
#undef ALIGN
#include <sysdeps/unix/i386/sysdep.h>

#endif /* mach/i386/sysdep.h */
