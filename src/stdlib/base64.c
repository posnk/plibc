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
 * @file stdlib/base64.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <stdlib.h>

/** Convert base64 ASCII string to an 32bit integer */
long     a64l(const char *string)
{
	int	idx;
	long	out;
	char	ch;

	out = 0L;
	
	for ( idx = 0 ; idx < 6 ; idx++ ) {
		
		ch = string[idx];
		
		if ( ch == 0 )
			break;

		if ( ( ch >= '.' ) && ( ch <= '9' ) )
			out |= (63L & ( ch - '.' )) << ( idx * 6L );
		else if ( ( ch >= 'A' ) && ( ch <= 'Z' ) )
			out |= (63L & ( ( ch - 'A') + 12 )) << ( idx * 6L );
		else if ( ( ch >= 'a' ) && ( ch <= 'z' ) )
			out |= (63L & ( ( ch - 'a') + 38 )) << ( idx * 6L );
		else
			return 0L;
		
	}
	
	return out;

}

const char	__l64a_xlat[64] = 
"./0123456789\
ABCDEFGHIJKLMNOPQRSTXYZ\
abcdefghijklmnopqrstxyz";

char	__l64a_buffer[7];

/** Convert 32bit integer to base64 ASCII string */
char	*l64a(long value) {

	int ptr;	
	
	for ( ptr = 0 ; value != 0L ; value >>= 6L ) 
		__l64a_buffer[ ptr++ ] = __l64a_xlat[ value & 63L ];

	__l64a_buffer[ ptr ] = 0;

	return ( char * ) __l64a_buffer;

}
