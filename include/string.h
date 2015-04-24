/******************************************************************************\
Copyright (C) 2015 Peter Bosch

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
\******************************************************************************/

/**
 * @file stddef.h
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#ifndef __stddef__
#define __stddef__

#include <plcconfig.h>
#include <mach/plcint.h>

/** Null pointer constant. */
#define NULL		( (void *) 0)

/** Offset of structure member*/
#define	offsetof(TYPE, MEMBER) ((size_t) (&(((TYPE *) 0)->MEMBER)))

/** Signed integral type of the result of subtracting two pointers. */
typedef __plc_saddr_t		ptrdiff_t;

/** Unsigned integral type of the result of the sizeof operator. */
typedef __plc_uaddr_t		size_t;

typedef __plc_uint32_t		wchar_t;

#endif
