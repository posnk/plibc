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

/** Unsuccessful termination for exit(), evaluates to a non-zero value. */
#define EXIT_FAILURE		(-1)

/** Successful termination for exit(), evaluates to 0. */
#define EXIT_SUCCESS		(0)

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

/** system - issue a command */
int	system(const char *cmd);

#endif


/* Mathematics functions */

/** div - compute the quotient and remainder of an integer division */
div_t		div	( int	n, int	d );

/** ldiv - compute quotient and remainder of a long division */
ldiv_t		ldiv	( long	n, int	d );

/** abs - return an integer absolute value  */
int		abs	( int	n );

/** labs - return a long absolute value  */
long		labs	( long	n );

/* Number conversion functions */

#ifdef PLIBC_HAVE_FLOATCONV

/** strtod - convert string to a double-precision number */
double		strtod	( const char *str, char **endptr);

/** atof - convert a string to double-precision number */
double		atof	( const char *str );

#endif

/** strtol - convert string to a long integer */
long int	strtol	( const char *str, char **endptr, int base );

/** strtol - convert string to an unsigned long integer */
unsigned long int
		strtoul	( const char *str, char **endptr, int base );

/** atoi - convert a string to integer */
int		atoi	( const char *str );

/** atol - convert a string to long integer */
long int	atol	( const char *str );


/* Memory management functions */

#ifdef PLIBC_HAVE_MEMORY_MGMT

/** malloc - a memory allocator */
void *		malloc	( size_t size );

/** free - free allocated memory */
void		free	( void * ptr );

/** calloc - a memory allocator */
void *		calloc	( size_t nelem, size_t elsize );

/** realloc - memory reallocator */
void *		realloc	( void *ptr,	size_t size );

/** valloc - page-aligned memory allocator (LEGACY) */
void *		valloc	( size_t size );

#endif

//TODO: Add remaining functions

#endif
