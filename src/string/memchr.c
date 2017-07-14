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
 * @file string/memchr.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <string.h>

/** memchr - find byte in memory */
void *		memchr	(	           const void *src, int c, size_t n)
{	
	char _c;
	const char *_s;
	size_t p;
	
	//TODO: Verify the behaviour for systems where sizeof(char) != 1 byte
	_c = c;
	_s = src;
	
	for ( p = 0; p < n; p++ )
		if ( _s[ p ] == _c )
			return ( void * ) ( _s + p );
		
	return NULL;

}
