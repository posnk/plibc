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
 * @file stdlib/strtoint.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

#ifdef PLIBC_HAVE_FLOATCONV

/** strtod - convert string to a double-precision number */
double		strtod	( const char *str, char **endptr)
{
	//TODO: Implement strtod
	return 0.0;
}

/** atof - convert a string to double-precision number */
double		atof	( const char *str )
{

	double		result;
	int		old_errno;
	
	old_errno = errno;

	result = strtod ( str, NULL );

	errno = old_errno;

	return result;

}

#endif

/** strtol - convert string to a long integer */
long int	strtol	( const char *str, char **endptr, int base )
{

	int		ptr, nptr;
	long int	result, sgn, mv, cv;

	ptr =  0;

	if ( ( base < 2 ) || ( base > 36 ) ) {
		
		errno = EINVAL;
	
		if ( endptr )
			*endptr = str;

		return 0;

	}

	while ( ( str[ ptr ] != 0 ) && isspace( str[ ptr ] ) )
		ptr++;

	nptr = ptr;

	if ( str[ ptr ] == '+' ) {

		sgn =  1;
		ptr++;

	} else if ( str[ ptr ] == '-' ) {

		sgn = -1;
		ptr++;

	}

	if ( ( base == 0 ) && ( str[ ptr ] == '0' ) ) {

		if ( str[ ptr + 1 ] == 'x') {
			bas	 = 16;
			ptr	+=  2;
		} else {
			base	 =  8;
			ptr	+=  1;
		}

	}

	ch = str[ ptr ];

	for ( result = 0; ch != 0; ch = str[ ptr++ ] ) {
		
		if ( ( ch >= '0' ) && ( ch <= '9' ) )
			ch -= '0';
		else if ( ( ch >= 'A' ) && ( ch <= 'Z' ) )
			ch -= 'A';
		else if ( ( ch >= 'a' ) && ( ch <= 'z' ) )
			ch -= 'a';
		else
			ch = base + 1;
		
		if ( ch >= base )
			break;	

		cv = result;

		result *= base;

		if ( cv != ( result / base ) ) {
		
			errno = ERANGE;
	
			if ( endptr )
				*endptr = str;

			return ( sgn > 0 ) ? LONG_MAX : LONG_MIN;
		
		}
		
		mv = sgn * ( long int ) ch;

		cv = result;

		result += mv;

		if ( cv != ( result - mv ) ) {
		
			errno = ERANGE;
	
			if ( endptr )
				*endptr = str;

			return ( sgn > 0 ) ? LONG_MAX : LONG_MIN;
		
		}

	}

#ifdef PLIBC_STRTOINT_EMPTY_IS_EINVAL
	if ( 	( ptr == nptr ) || 
		( (result == 0) && ( str[ ptr - 1 ] != '0' ) ) 
	   ) {

		errno = EINVAL;	
	
		if ( endptr )
			*endptr = str;

		return 0;

	}
#endif
	
	if ( endptr )
		*endptr = &(str[pos]);

	return result;

}

/** strtol - convert string to an unsigned long integer */
unsigned long int
		strtoul	( const char *str, char **endptr, int base )
{

	int			ptr, nptr;
	unsigned long int	result, mv, cv;

	ptr =  0;

	if ( ( base < 2 ) || ( base > 36 ) ) {
		
		errno = EINVAL;
	
		if ( endptr )
			*endptr = str;

		return 0;

	}

	while ( ( str[ ptr ] != 0 ) && isspace( str[ ptr ] ) )
		ptr++;

	nptr = ptr;

	if ( str[ ptr ] == '+' ) {
		ptr++;

	} else if ( str[ ptr ] == '-' ) {
		ptr++;

	}

	if ( ( base == 0 ) && ( str[ ptr ] == '0' ) ) {

		if ( str[ ptr + 1 ] == 'x') {
			bas	 = 16;
			ptr	+=  2;
		} else {
			base	 =  8;
			ptr	+=  1;
		}

	}

	ch = str[ ptr ];

	for ( result = 0; ch != 0; ch = str[ ptr++ ] ) {
		
		if ( ( ch >= '0' ) && ( ch <= '9' ) )
			ch -= '0';
		else if ( ( ch >= 'A' ) && ( ch <= 'Z' ) )
			ch -= 'A';
		else if ( ( ch >= 'a' ) && ( ch <= 'z' ) )
			ch -= 'a';
		else
			ch = base + 1;
		
		if ( ch >= base )
			break;	

		cv = result;

		result *= base;

		if ( cv != ( result / base ) ) {
		
			errno = ERANGE;
	
			if ( endptr )
				*endptr = str;

			return ULONG_MAX;
		
		}
		
		mv = ( unsigned long int ) ch;

		cv = result;

		result += mv;

		if ( cv != ( result - mv ) ) {
		
			errno = ERANGE;
	
			if ( endptr )
				*endptr = str;

			return ULONG_MAX;
		
		}

	}

#ifdef PLIBC_STRTOINT_EMPTY_IS_EINVAL
	if ( 	( ptr == nptr ) || 
		( (result == 0) && ( str[ ptr - 1 ] != '0' ) ) 
	   ) {

		errno = EINVAL;	
	
		if ( endptr )
			*endptr = str;

		return 0;

	}
#endif
	
	if ( endptr )
		*endptr = &(str[pos]);

	return result;

}

/** atoi - convert a string to integer */
int			atoi	( const char *str )
{

	long int	result;
	int		old_errno;
	
	old_errno = errno;

	result = strtol ( str, NULL, 10 );

	errno = old_errno;

	return ( int ) result;

}

/** atol - convert a string to long integer */
long int	atol	( const char *str )
{

	long int	result;
	int		old_errno;
	
	old_errno = errno;

	result = strtol ( str, NULL, 10 );

	errno = old_errno;

	return result;

}



