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
 * @file string/strtok_r.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <string.h>

/** strtok_r - split string into tokens */
char *		strtok_r(char *s,          const char *delim, char **lasts  )
{

	char *tk;
	
	if ( s )
		*lasts = s;
	else
		s = *lasts;
		
	if ( !s )
		return NULL;
	
	while ( tk == s ) {
		tk = strpbrk( s, delim );
		*tk = 0;
		s++;
	}
	
	if ( !tk ) {
		*lasts = NULL;
	} else {
		*lasts = tk + 1;
	}
	
	if ( *s )
		return s;
	return NULL;
	
}
