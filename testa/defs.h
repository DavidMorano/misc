/* defs (logname) */

/* Copyright � 1998 David A�D� Morano.  All rights reserved. */


#ifndef	DEFS_INCLUDE
#define	DEFS_INCLUDE	1


#include	<envstandards.h>

#include	<sys/types.h>

#include	<bfile.h>
#include	<localmisc.h>


#define	BUFLEN		100
#define	USAGECOLS	4


struct proginfo_flags {
	uint	outfile : 1 ;
	uint	errfile : 1 ;
	uint	quiet : 1 ;
} ;

struct proginfo {
	char		**envv ;
	char		*pwd ;
	char		*progdname ;
	char		*progname ;
	char		*version ;
	char		*banner ;
	char		*searchname ;
	char		*pr ;
	char		*helpfname ;
	bfile		*efp ;
	struct proginfo_flags	f ;
	int		debuglevel ;
	int		verboselevel ;
} ;


#endif /* DEFS_INCLUDE */


