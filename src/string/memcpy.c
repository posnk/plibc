/******************************************************************************\
Copyright (C) 2017 Peter Bosch

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
 * @file string/memcpy.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <string.h>

/** memcpy - copy bytes in memory */
void *		memcpy	(      void *dest, const void *src,        size_t n)
{	
	const char *_s;
	char *_d;
	size_t p;
	
	//TODO: Verify the behaviour for systems where sizeof(char) != 1 byte
	_s = src;
	_d = dest;
	
	for ( p = 0; p < n; p++ )
		_d[ p ] = _s[ p ];
		
	return dest;

}
