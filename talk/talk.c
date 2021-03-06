/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ident	"@(#)talk.c	1.6	94/10/04 SMI"	/* SVr4.0 1.2	*/

/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 		PROPRIETARY NOTICE (Combined)
 *
 * This source code is unpublished proprietary information
 * constituting, or derived under license from AT&T's UNIX(r) System V.
 * In addition, portions of such source code were derived from Berkeley
 * 4.3 BSD under license from the Regents of the University of
 * California.
 *
 *
 *
 * 		Copyright Notice
 *
 * Notice of copyright on this source code product does not indicate
 * publication.
 *
 * 	(c) 1986,1987,1988.1989  Sun Microsystems, Inc
 * 	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
 *		All rights reserved.
 *
 */


#include "talk.h"
#include <locale.h>



/*
 * talk:	A visual form of write. Using sockets, a two way
 *		connection is set up between the two people talking.
 *		With the aid of curses, the screen is split into two
 *		windows, and each users text is added to the window,
 *		one character at a time...
 *
 */

int main(argc, argv)
int	argc ;
char	*argv[] ;
{
	register	c;


	(void) setlocale(LC_ALL, "");

#if !defined(TEXT_DOMAIN)	/* Should be defined by cc -D */
#define	TEXT_DOMAIN "SYS_TEST"
#endif

	(void) textdomain(TEXT_DOMAIN);

	while ((c = getopt(argc, argv, "")) != EOF) {

		switch (c) {
			case '?':
				(void) fprintf(stderr,"Usage: talk %s\n",
					gettext("address [terminal]"));
				exit(2);
		}

	} /* end while */

	get_names(argc, argv);

	init_display();

	open_ctl();

	open_sockt();

	start_msgs();

	if (! check_local()) {

		invite_remote();

	}

	end_msgs();

	set_edit_chars();


/* do the deed */

	talk();


/* we're out of here */

	fclose(stdout) ;

	fclose(stderr) ;

	return 0 ;
}
/* end subroutine (main) */




