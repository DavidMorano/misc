/* main (testansiANSI) */

/* test something to do with ANSI compliance */

#define	CF_MINUSONE	0

#include	<envstandards.h>
#include	<bfile.h>
#include	<localmisc.h>


/* external subroutines */

extern int	minus_one(int) ;


/* forward references */

static int printsub(bfile *,uint) ;


/* exported subroutines */


int main()
{
	bfile		ofile, *ofp = &ofile ;
	unsigned int	ui, uv ;
	unsigned short	us ;
	unsigned char	uc ;
	int		v, i ;
	char		ch ;


	ui = 26U ;

	(void) bopen(ofp,BFILE_STDOUT,"wct",0666) ;

#if	CF_MINUSONE
	v = minus_one(1) ;
#else
	v = -1 ;
#endif

	uc = (uchar) v ;
	us = 0xFFFF ;
	ui = us ;
	i = us ;


	if (us < v) {
		bprintf(ofp,"less (K&R)\n") ;
	} else if (us > v) {
		bprintf(ofp,"greater (ANSI)\n") ;
	} else {
		bprintf(ofp,"equal\n") ;
	}

	bprintf(ofp,"uc=%08X us=%08X ui=%08X i=%08X\n",
		uc,us,ui,i) ;

	uv = v ;
	bprintf(ofp,"v=%08X uv=%08X\n",
		v,uv) ;


/* second experiment */

	uc = 0xFF ;
	v = uc ;
	bprintf(ofp,"uc=%04x v=%08x\n",uc,v) ;

	printsub(ofp,uc) ;

	ch = 0xff ;
	v = ch ;
	bprintf(ofp,"ch=%04x v=%08x\n",ch,v) ;

	printsub(ofp,ch) ;

/* third experiment */

	uv = ch ;
	bprintf(ofp,"ch=%08x uv=%08x\n",ch,uv) ;

	{
	    uchar	uc = 0xff ;
	    uv = uc ;
	    bprintf(ofp,"uc=%08x uv=%08x\n",ch,uv) ;
	}

/* out of here */

	bclose(ofp) ;

	return 0 ;
}
/* end subroutine (main) */


/* local subroutines */


static int printsub(bfile *fp,uint v)
{
	return bprintf(fp,"%08x\n",v) ;
}
/* end subroutine (printsub) */

