
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
#include "mydef.h"
#include "dmalib.h"

static struct dma_op
{
	BYTE dmode;
	BYTE page;
	DWORD len;

	BYTE maskadr;
	BYTE enable;
	BYTE disable;

	BYTE flip;
	BYTE adradr;
	BYTE cntadr;
	BYTE pageadr;
	BYTE cmdadr;

	BYTE cmd;
} dma_data[8];

static WORD dma_adr[8]={0,2,4,6,0xc0,0xc2,0xc4,0xc6};
static WORD dma_cnt[8]={1,3,5,7,0xc1,0xc3,0xc5,0xc7};
static WORD dma_page[8]={0x87,0x83,0x81,0x82,0x8f,0x8b,0x89,0x8a};

DWORD far2long(char far *adr)
{
	return(((DWORD)FP_SEG(adr)<<4)+FP_OFF(adr));
}

WORD dma_set(DWORD adrl,DWORD len,int channel,BYTE mode)
{
	WORD subcount,adr;
	DWORD lenl;
	struct dma_op *ptr;
	BYTE page;

	ptr=&dma_data[channel];

	lenl=len;

	if(channel>3)
	{
		adrl>>=1;
		lenl>>=1;
	}

	subcount=~(WORD)adrl+1;         /* calculate to page boundary */
	if(lenl<subcount) subcount=lenl;

	adr=(WORD)adrl;
	page=(BYTE)(adrl>>16);

	ptr->len=lenl-subcount; /* calc len for next event */
	ptr->dmode=mode;
	ptr->page=page+1;

	if(channel>3)    /* setup addresses */
	{
		ptr->maskadr=0xd4;
		ptr->cmdadr=0xd6;
		ptr->flip=0xd8;
	}
	else
	{
		ptr->maskadr=0xa;
		ptr->cmdadr=0xb;
		ptr->flip=0xc;
	}
	ptr->cmd=(BYTE)channel|mode;
	ptr->enable=(BYTE)channel;
	ptr->disable=(BYTE)channel|4;

	ptr->cntadr=dma_cnt[channel];
	ptr->adradr=dma_adr[channel];
	ptr->pageadr=dma_page[channel];

	asm cli;

	_DX=ptr->maskadr;
	_AL=ptr->disable;
	asm out dx,al;     /* disable channel */

	_DX=ptr->cmdadr;
	_AL=ptr->cmd;
	asm out dx,al;     /* set dma mode */

	_DX=ptr->flip;
	asm out dx,al;     /* reset flipflop */

	_DX=ptr->adradr;
	asm mov ax,adr;
	asm out dx,al;
	asm mov al,ah;
	asm out dx,al;				/* set address */

	_DX=ptr->pageadr;
	asm mov al,page;
	asm out dx,al;     /* set page */

	_DX=ptr->flip;
	asm out dx,al;     /* reset flipflop */

	_DX=ptr->cntadr;
	asm mov ax,subcount;
	asm dec ax;                /* decrement length */
	asm out dx,al;
	asm mov al,ah;
	asm out dx,al;				/* set length */

	_DX=ptr->maskadr;
	_AL=ptr->enable;
	asm out dx,al;     /* enable channel */

	asm sti

	return(subcount);
}

WORD dma_next(int channel)
{
	WORD subcount;
	DWORD len;
	struct dma_op *ptr;

	ptr=&dma_data[channel];
	len=ptr->len;
	if(!len) return(0); /* dma done */
	if(len>65536L)
	{
		ptr->len-=65536;
		subcount=0;
	}
	else
	{
		ptr->len=0;
		subcount=(WORD)len;
	}

	asm cli;

	_DX=ptr->maskadr;
	_AL=ptr->disable;
	asm out dx,al;     /* disable channel */

	_DX=ptr->cmdadr;
	_AL=ptr->cmd;
	asm out dx,al;     /* set dma mode */

	_DX=ptr->flip;
	asm out dx,al;     /* reset flipflop */

	_DX=ptr->adradr;
	asm mov al,0
	asm out dx,al;
	asm out dx,al;				/* set address NULL */

	_DX=ptr->pageadr;
	_AL=ptr->page++;
	asm out dx,al;     /* set page */

	_DX=ptr->flip;
	asm out dx,al;     /* reset flipflop */

	_DX=ptr->cntadr;
	asm mov ax,subcount;
	asm dec ax;                /* decrement length */
	asm out dx,al;
	asm mov al,ah;
	asm out dx,al;				/* set length */

	_DX=ptr->maskadr;
	_AL=ptr->enable;
	asm out dx,al;     /* enable channel */

	asm sti
	return(subcount);
}

long dma_len(int channel)
{
	return(dma_data[channel].len);
}


