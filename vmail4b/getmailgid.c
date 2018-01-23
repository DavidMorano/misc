/* getgid_def */

/* get the GID for a named group or default to a specified value on failure */


/* revision history:

	= 1998-08-20, David A�D� Morano
	This was written to collect this code into one subroutines.

*/

/* Copyright � 1998 David A�D� Morano.  All rights reserved. */

/*******************************************************************************

	This subroutine returns a GID for a specified groupname.  A default GID
	is returned if the groupname does not exist.

	Synopsis:
	int getgid_def(cchar *gname,gid_t gid)

	Arguments:
	gname		groupname to lookup
	gid		default GID if lookup fails

	Returns:
	-		GID found or the default GID


*******************************************************************************/


#include	<envstandards.h>

#include	<sys/types.h>

#include	<vsystem.h>
#include	<localmisc.h>


/* local defines */


/* external subroutines */

extern int	getgid_group(cchar *,int) ;


/* exported subroutines */


int getgid_def(cchar *gname,gid_t gid)
{
	const int	rsn = SR_NOTFOUND ;
	int		rs ;
	if (gname == NULL) return SR_FAULT ;
	if ((rs = getgid_group(gname,-1)) == rsn) {
	    if (gid >= 0) {
	        rs = gid ;
	    } else {
	        rs = getgid() ;
	    }
	}
	return rs ;
}
/* end subroutine (getgid_def) */


