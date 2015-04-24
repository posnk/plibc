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
 * @file mach/i386/plcint.h
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#ifndef __plcint__
#define __plcint__

#include <plcconfig.h>

typedef 	unsigned char		__plc_uint8_t;
typedef 	unsigned short		__plc_uint16_t;
typedef 	unsigned int		__plc_uint32_t;
typedef 	unsigned long long	__plc_uint64_t;

typedef 	signed char			__plc_sint8_t;
typedef 	signed short		__plc_sint16_t;
typedef 	signed int			__plc_sint32_t;
typedef 	signed long long	__plc_sint64_t;

typedef 	unsigned int		__plc_uaddr_t;
typedef 	signed int			__plc_saddr_t;

#endif
