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
 * @file stdlib/math.c
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#include <plcconfig.h>
#include <stdlib.h>

/** div - compute the quotient and remainder of an integer division */
div_t	div	( int	n, int	d )
{

	div_t	result;

	result.quot	= n / d;
	result.rem	= n % d;

	if ( ( n >= 0 ) && ( result.rem < 0 ) ) {
		result.quot++;
		result.rem -= d;
	}

	return result;

}

/** ldiv - compute quotient and remainder of a long division */
ldiv_t	ldiv	( long	n, int	d )
{

	ldiv_t	result;

	result.quot	= n / d;
	result.rem	= n % d;

	if ( ( n >= 0L ) && ( result.rem < 0L ) ) {
		result.quot++;
		result.rem -= d;
	}

	return result;

}

/** abs - return an integer absolute value  */
int	abs	( int	n )
{
	return ( n < 0 ) ? ( -n ) : ( n );
}

/** labs - return a long absolute value  */
long	labs	( long	n )
{
	return ( n < 0L ) ? ( -n ) : ( n );
}
