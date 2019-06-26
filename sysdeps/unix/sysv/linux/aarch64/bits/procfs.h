/* Types for registers for sys/procfs.h.  AArch64 version.
   Copyright (C) 1996-2019 Free Software Foundation, Inc.

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
   <http://www.gnu.org/licenses/>.  */

#ifndef _BITS_PROCFS_H
#define _BITS_PROCFS_H 1

#if !defined _SYS_PROCFS_H && !defined _BITS_UCONTEXT_H
# error "Never include <bits/procfs.h> directly; use <sys/procfs.h> instead."
#endif

#include <bits/types.h>
#include <sys/user.h>

/* Type for a general-purpose register.  */
typedef __uint64_t elf_greg_t;

/* And the whole bunch of them.  We could have used `struct
   user_regs_struct' directly in the typedef, but tradition says that
   the register set is an array, which does have some peculiar
   semantics, so leave it that way.

   struct user_regs_struct is defined in sys/user.h.  */
#define ELF_NGREG (sizeof (struct user_regs_struct) / sizeof (elf_greg_t))
typedef elf_greg_t elf_gregset_t[ELF_NGREG];

/* Register set for the floating-point registers.  */
typedef struct user_fpsimd_struct elf_fpregset_t;

#endif /* bits/procfs.h */
