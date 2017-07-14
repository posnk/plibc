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
 * @file string/strspn.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <string.h>
#include <limits.h>

/** strspn - get number of prefix chars in accept */
size_t           strspn	(const char *s1,   const char *accept              )
{

	const char *ap,*sp;
	for ( sp = s1; *sp; sp++ ) {
		for ( ap = accept; *ap; ap++ ) {
			if ( *ap == *sp )
				break;
		}
		if ( ! *ap )
			break;
	}
	
	return ( size_t ) ( sp - s1 );
		
}

/** strcspn - get number of prefix chars not in reject */
int             strcspn	(const char *s1,   const char *reject              )
{

	const char *ap,*sp;
	for ( sp = s1; *sp; sp++ ) {
		for ( ap = accept; *ap; ap++ ) {
			if ( *ap == *sp )
				break;
		}
		if ( *ap )
			break;
	}
	
	return ( size_t ) ( sp - s1 );
		
}