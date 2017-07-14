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
 * @file string/memcmp.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <string.h>

/** memcmp - compare bytes in memory */
int		memcmp	(const void *s1,   const void *s2,         size_t n);
{	
	const char *_s1, *_s2;
	size_t p;
	int r;
	
	//TODO: Verify the behaviour for systems where sizeof(char) != 1 byte
	_s = src;
	_d = dest;
	
	r = 0;
	
	for ( p = 0; p < n; p++ ) {
		r = _s1[ p ] - _s2[ p ];
		if ( r )
			break;
	}
		
	return r;

}
