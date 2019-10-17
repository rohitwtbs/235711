
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


#include <fcntl.h>
#include <malloc.h>
#include <sys\stat.h>
#include "mydef.h"

void main(int argc,char *argv[])
{
	int file;
	WORD ret;
	struct stat mystat;
	long length,TC;
	char huge *base,huge *base2;
	DWORD blklen,rate;
	BYTE tmp,tmp2,huge *ptr;

	if(argc==2)
	{
		if(stat(argv[1],&mystat))
		{
			printf("file %s does'nt exist\n",argv[1]);
			return;
		}
		length=mystat.st_size;
		printf("File Size: %lu\n",length);
		base=farmalloc(length);
		if(!base)
		{
			printf("Not enough memory!");
			return;
		}
		file=open(argv[1],O_RDONLY|O_BINARY);
		if(file== -1)
		{
			printf("Cannot open file!");
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

		ptr=base;
		if(strncmp(ptr,"Creative Voice File\x1a",20) || *((WORD *)ptr+11)!=(~*((WORD *)ptr+12)+0x1234))
		{
			printf("No voc file!\n");
			if(base) farfree(base);
			return;
		}
		printf("Creative Voice File\n");
		printf("version: %d.%d\n\n",*(ptr+0x17),*(ptr+0x16));

		ptr+=*((WORD *)ptr+10);
		while(*ptr)
		{
			blklen=((DWORD)(*(ptr+3))<<16)+ *((WORD *)(ptr+1))+4;
			switch(*ptr)
			{
				case 1: printf("Block Type-1 Voice Data\n");
						printf("Sample Rate: %ld\n",1000000L/(256l-*(ptr+4)));
						printf("PACK: ");
						tmp=*(ptr+5);
						if(tmp==0) printf("8-bit unpacked\n");
						if(tmp==1) printf("4-bit packed\n");
						if(tmp==2) printf("2.6-bit packed\n");
						if(tmp==3) printf("2-bit packed\n");
					break;
				case 2: printf("Block Type-2 Voice Continuation\n\n");
					break;
				case 3: printf("Block Type-3 Silence\n");
						printf("Length: %u periods\n",*((WORD *)(ptr+4)));
						printf("Sample Rate: %ld\n",1000000L/(256l-*(ptr+6)));
					break;
				case 4: printf("Block Type-4 Marker\n");
					break;
				case 5: printf("Block Type-5 ASCII Text\n");
						printf("Text: %s\n",ptr+4);
					break;
				case 6: printf("Block Type-6 Repeat Loop\n");
						printf("Count: %u\n",*((WORD *)(ptr+4)));
					break;
				case 7: printf("Block Type-7 End Repeat Loop\n");
					break;
				case 8: printf("Block Type-8 Extended Block\n");
						rate=256000000L/(65536l-*((WORD *)ptr+2));
						tmp2=*(ptr+7);
						if(tmp2) rate>>=1;
						printf("Sample Rate: %lu\n",rate);
						tmp=*(ptr+6);
						if(tmp==0) printf("8-bit unpacked\n");
						if(tmp==1) printf("4-bit packed\n");
						if(tmp==2) printf("2.6-bit packed\n");
						if(tmp==3) printf("2-bit packed\n");
						if(tmp2) printf("Stereo\n");
						else printf("Mono\n");
					break;
				default: printf("Unkown Block Type-%u!\n",*ptr);
			}
			ptr+=blklen;
			printf("Blocklength: %lu\n\n",blklen-4);
		}
		printf("Block Type-0 Terminator\n");
	}
	else printf("usage: voclook filename\n");
}
