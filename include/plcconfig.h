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
 * @file plcconfig.h
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#ifndef __plcconfig__
#define __plcconfig__

#define PLIBC_VERSION		("plibc-0.1")

#define PLIBC_LOCALE_CHAR_SIZE	(1)

#define PLIBC_STRTOINT_EMPTY_IS_EINVAL

#undef PLIBC_HAVE_FLOATCONV

#ifdef PLIBC_FREESTANDING

#undef PLIBC_HAVE_PROCESS_MGMT
#undef PLIBC_HAVE_SYS_WAIT

#else

#define PLIBC_HAVE_PROCESS_MGMT
#define PLIBC_HAVE_SYS_WAIT

#endif

#endif
