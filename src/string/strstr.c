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
 * @file string/strstr.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <string.h>

/** strstr -  scan a string for a byte */
char *          strstr	(const char *s1,   const char *s2                  )
{

	const char *ap,*sp,*sp2;
	
	for ( sp = s1; *sp; sp++ ) {
		sp2 = sp;
		for ( ap = s2; *ap; ap++ ) {
			if ( *ap != *sp2++ )
				break;
		}
		if ( !*ap )
			return ( char * ) sp;
			
	}
	
	return NULL;
		
}
