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
 * @file string.h
 *
 * Part of plibc
 *
 * Written by Peter Bosch <peterbosc@gmail.com>
 *
 */

#ifndef __string__
#define __string__

#include <plcconfig.h>
#include <mach/plcint.h>

#include <stddef.h>

/** memccpy - copy bytes in memory */
void *		memccpy	(void *dest,       const void *src, int c, size_t n);

/** memchr - find byte in memory */
void *		memchr	(	           const void *src, int c, size_t n);

/** memcmp - compare bytes in memory */
int		memcmp	(const void *s1,   const void *s2,         size_t n);

/** memcpy - copy bytes in memory */
void *		memcpy	(      void *dest, const void *src,        size_t n);

/** memmove - copy bytes in memory with overlapping areas */
void *		memmove	(      void *dest, const void *src,        size_t n);

/** memset - set bytes in memory */
void *		memset	(      void *dest,                  int c, size_t n);
	
/** strcat - concatenate two strings */
char *		strcat	(      char *dest, const char *src                 );
	
/** strchr - string scanning operation */
char *		strchr	(                  const char *src, int c	   );

/** strcmp - compare two strings */
int             strcmp	(const char *s1,   const char *s2                  );

/** strcpy - copy a string */
char *		strcpy	(      char *dest, const char *src                 );

//TODO: Add strcoll
#define		strcoll	strcmp

/** strspn - get number of prefix chars in accept */
size_t           strspn	(const char *s1,   const char *accept              );

/** strcspn - get number of prefix chars not in reject */
size_t          strcspn	(const char *s1,   const char *reject              );

/** strdup - duplicate a string */
char *		strdup	(                  const char *src                 );
	
/** strlen - get string length */
size_t		strlen	(                  const char *src                 );

/** strerror - get error message string */
char *		strerror( int errnum );
	
/** strncat - concatenate two strings */
char *		strncat	(      char *dest, const char *src,        size_t n);

/** strncmp - compare two strings */
int		strncmp	(const char *s1,   const char *s2,         size_t n);

/** strncpy - copy a string */
char *		strncpy	(      char *dest, const char *src,        size_t n);
	
/** strrchr - string scanning operation */
char *		strrchr	(                  const char *src, int c           );

/** strpbrk -  scan a string for a byte */
char *          strpbrk	(const char *s1,   const char *s2                   );

/** strstr  -  scan a string for a string */
char *          strstr	(const char *s1,   const char *s2                   );

/** strtok, strtok_r - split string into tokens */
char *		strtok	(char *s,          const char *delim                );
char *		strtok_r(char *s,          const char *delim, char **lasts  ); 

//TODO: Add strxfrm
	
	
#endif
