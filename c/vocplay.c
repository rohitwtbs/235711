
/* Copyright 1993 by Peter Sprenger   Pete@amber.dinoco.de
 *                   5014 Kerpen 3
 *                   Germany
 *
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies.  The author Peter Sprenger
 * makes no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without
 * express or implied warranty.
 */


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <io.h>
#include <fcntl.h>
#include <alloc.h>
#include <sys\stat.h>
#include "mydef.h"
#include "sound.h"
#include "timerx.h"
#include "dmalib.h"


extern volatile BYTE voc_mode;

void main(int argc,char *argv[])
{
	int file;
	WORD ret,rate;
	struct stat mystat;
	long length;
	char huge *base,huge *base2;
	BYTE left,right;


	if(argc==2)
	{
		stat(argv[1],&mystat);
		length=mystat.st_size;
		base=farmalloc(length);
		if(!base)
		{
			printf("Not enough memory\n");
			return;
		}
		file=open(argv[1],O_RDONLY|O_BINARY);
		if(file== -1)
		{
			printf("Cannot open file\n");
			if(base) farfree(base);
			return;
		}
		base2=base;
		do
		{
			ret=read(file,base2,32700);  /* do not use this call in small model! */
			base2+=ret;
		} while(ret==32700);
		close(file);

		if(SB_Setup())
		{
			SB_SetVect(sample);
			if(!VocPlay((char far *)base)) printf("No vocfile!\n");
			else while(!kbhit() && voc_mode);

			VocStop();
			SB_RemoveVect();
		}
		farfree(base);
	}
	else printf("usage: vocplay filename\n");
}
