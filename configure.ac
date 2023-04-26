#
# configure.ac -- Autoconf macros testing for simdzone features
#
# Copyright (c) 2022-2023, NLnet Labs. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# This file is intended for inclusion by configure.ac in NSD. Support for any
# platform not supported by NSD here is undesirable. Builds for standalone use
# or development/testing are required to use CMake.


AC_INIT([simdzone],[0.1.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_PROG_CC
AC_CONFIG_HEADERS([config.h])

#m4_version_prereq([2.70], [AC_PROG_CC], [AC_PROG_CC_STDC])
AC_CONFIG_FILES([Makefile src/Makefile])

# Figure out the canonical target architecture.
AC_CANONICAL_TARGET

# Multiple instruction sets may be supported by a specific architecture.
# e.g. x86_64 may (or may not) support any of SSE42, AVX2 and AVX-512. The
# best instruction set is automatically selected at runtime, but the compiler
# may or may not support generating code for an instruction set.
case "$target" in
  *amd64*)  x86_64=yes ;;
  *x86_64*) x86_64=yes ;;
  *)                   ;;
esac

sinclude(m4/ax_check_compile_flag.m4)

if test $x86_64 = "yes"; then
  AC_CHECK_HEADER(immintrin.h,,,)
  AX_CHECK_COMPILE_FLAG([-march=westmere],,,[-Werror])
  AX_CHECK_COMPILE_FLAG([-march=haswell],,,[-Werror])

  if test $ac_cv_header_immintrin_h = "yes" -a \
          $ax_cv_check_cflags__Werror__march_westmere = "yes"
  then
    AC_DEFINE(HAVE_WESTMERE, 1, [Wether or not to compile support for SSE4.2])
  fi

  if test $ac_cv_header_immintrin_h = "yes" -a \
          $ax_cv_check_cflags__Werror__march_haswell = "yes"
  then
    AC_DEFINE(HAVE_HASWELL, 1, [Wether or not to compile support for AVX2])
  fi
fi

AM_CONDITIONAL([WESTMERE], [ test x$ax_cv_check_cflags__Werror__march_westmere = xyes ])
AM_CONDITIONAL([HASWELL], [ test x$ax_cv_check_cflags__Werror__march_haswell = xyes ])

AC_OUTPUT
