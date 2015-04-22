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
 * @file stdlib.h
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#ifndef __stdlib__
#define __stdlib__
#include <plcconfig.h>

#ifndef PLIBC_FREESTANDING

	/** Unsuccessful termination for exit(), evaluates to a 
	    non-zero value. */
#	define EXIT_FAILURE		(-1)

	/** Successful termination for exit(), evaluates to 0. */
#	define EXIT_SUCCESS		(0)

#endif

/* Provide NULL, size_t and wchar_t */
#include <stddef.h>

/** Maximum value returned by rand(), at least 32,767. */
#define RAND_MAX			(32767)

/** Integer expression whose value is the maximum number of bytes in a character
    specified by the current locale. */
#define MB_CUR_MAX			(PLIBC_LOCALE_CHAR_SIZE)

#ifdef PLIBC_HAVE_SYS_WAIT

	/* For system() */
	#include <sys/wait.h>

#endif

/** Type returned by div */
typedef struct {

	/** quotient */
	int quot;
	
	/** remainder */
	int rem;

} div_t;

/** Type returned by ldiv */
typedef struct {

	/** quotient */
	long int quot;
	
	/** remainder */
	long int rem;

} ldiv_t;

/* Base-64 functions */

/** Convert base64 ASCII string to an 32bit integer */
long     a64l(const char *string);

/** Convert 32bit integer to base64 ASCII string */
char	*l64a(long value);

/* Process management functions */

/** Terminate the program unsuccessfully */
void	 abort( void );

#ifdef PLIBC_HAVE_PROCESS_MGMT

/** Register function to be run on exit */
int	atexit(void (*)(void));

/** Terminate the program and return value */
void	exit( int value );

int	system(const char *cmd);

#endif



#endif
