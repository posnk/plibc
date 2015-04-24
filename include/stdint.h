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
 * @file stdint.h
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#ifndef __stdint__
#define __stdint__
#include <plcconfig.h>
#include <mach/plcint.h>

typedef		__plc_uint8_t		uint8_t;
typedef		__plc_uint16_t		uint16_t;
typedef		__plc_uint32_t		uint32_t;
typedef		__plc_uint64_t		uint64_t;

typedef		__plc_sint8_t		int8_t;
typedef		__plc_sint16_t		int16_t;
typedef		__plc_sint32_t		int32_t;
typedef		__plc_sint64_t		int64_t;

typedef		__plc_uint8_t		uint_least8_t;
typedef		__plc_uint16_t		uint_least16_t;
typedef		__plc_uint32_t		uint_least32_t;
typedef		__plc_uint64_t		uint_least64_t;

typedef		__plc_sint8_t		int_least8_t;
typedef		__plc_sint16_t		int_least16_t;
typedef		__plc_sint32_t		int_least32_t;
typedef		__plc_sint64_t		int_least64_t;

typedef		__plc_uint8_t		uint_fast8_t;
typedef		__plc_uint16_t		uint_fast16_t;
typedef		__plc_uint32_t		uint_fast32_t;
typedef		__plc_uint64_t		uint_fast64_t;

typedef		__plc_sint8_t		int_fast8_t;
typedef		__plc_sint16_t		int_fast16_t;
typedef		__plc_sint32_t		int_fast32_t;
typedef		__plc_sint64_t		int_fast64_t;

typedef		__plc_uaddr_t		uintptr_t;
typedef		__plc_saddr_t		intptr_t;

typedef		__plc_uint64_t		uintmax_t;
typedef		__plc_sint64_t		intmax_t;

#endif
