
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

static WORD ioaddr[6]={0x220,0x240,0x210,0x230,0x250,0x260};
static WORD FM_off[9]={0,0x100,0x200,0x800,0x900,0xa00,0x1000,0x1100,0x1200};
static BYTE FM_fnr[12]={0x57,0x6b,0x81,0x98,0xb0,0xca,0xe5,0x02,0x20,0x41,0x63,0x87};
static BYTE FM_key_or[12]={1,1,1,1,1,1,1,2,2,2,2,2};
static BYTE intrx[5]={7,5,2,3,10};
static BYTE FM_key[9],FM_vol[9];

WORD io_addr,intnr,dma_ch,card_id,fm_addr,fm_left,fm_right,fm_both;
static WORD mue3,mue23,dsp_vers,wh_card,rythm,rx,ry,midi_buflen;
static WORD voccnt,cnt;

static BYTE DSP_intr_mode,DSP_high_mode,midi_mode,far *midi_recv;
volatile BYTE voc_mode,tst_cnt,dma_sb_busy;
static BYTE huge *vocptr,huge *vocrem,voc_ext,voc_pmode;
static DWORD voc_blklen;

static void far interrupt (*orgint)();


/*  ---------------  FM  Stuff ------------ */


void FM_Write(WORD data)
{
	asm mov dx,fm_addr;
	asm mov ax,data;

	asm xchg al,ah;
	asm out dx,al;

	asm mov cx,mue3;
loop1:
	asm loop loop1;

	asm inc dx;
	asm mov al,ah;
	asm out dx,al;

	mdelay(mue23);
}

void FM_Reset()
{
	FM_SetChan(both);
	FM_Write(0x0120);
	FM_Write(0x0800);
	FM_Write(0xbdc0);
}

BYTE FM_Status()
{
	asm mov dx,fm_addr;
	asm in al,dx;
	return(_AL);
}

static int FM_Detect()
{
	int i;

	FM_Write(0x0100); /* init Test register */

	FM_Write(0x0460); /* reset both timer */
	FM_Write(0x0480); /* enable interrupts */
	if(FM_Status() & 0xe0) return(FALSE);

	FM_Write(0x02ff); /* write ffh to timer 1 */
	FM_Write(0x0421); /* start timer 1 */
	if(fm_addr==0x388) msdelay(21); /* wait 21000 mcs */
	else mdelay(mcalc(80));   /* wait at least 80 microsec */
	if((FM_Status() & 0xe0)!=0xc0) return(FALSE);

	FM_Write(0x0460); /* reset both timer */
	FM_Write(0x0480); /* enable interrupts */
	return(TRUE);
}

void FM_SetChan(fm_chan channel)
{
	if(channel!=sbpro) return;
	switch(channel)
	{
		case both:
				   fm_addr=fm_both;
				 break;
		case left:
				   fm_addr=fm_left;
				 break;
		case right:
				   fm_addr=fm_right;
	}
}

void FM_SetVoice(BYTE voice,BYTE *ins)
{
	BYTE *insptr;
	WORD data;
	int i;

	insptr=ins;

	FM_vol[voice]=insptr[3];
	data=0x2000+FM_off[voice];

	for(i=0;i<5;i++)
	{
		data=data&0xff00| *insptr++;
		FM_Write(data);
		data+=0x300;
		data=data&0xff00| *insptr++;
		FM_Write(data);
		data=data+(0x2000-0x300);
		if(i==3) data+=4000;
	}
	data=0xc000+(voice<<8);
	data=data&0xff00| *insptr;
	FM_Write(data);
}

void FM_SetNote(BYTE voice,BYTE note)
{
	BYTE blk,notex;
	WORD data;

	notex=note-24;
	blk=1;
	while(notex>=12)
	{
		notex-=12;
		blk++;
	}
	data=0xa000+(voice<<8)|FM_fnr[notex];
	FM_key[voice]=FM_key_or[notex]|(blk<<2);
	FM_Write(data);
}

void FM_SetVol(BYTE voice,BYTE vol)
{
   FM_Write(0x4320+FM_off[voice]-(((BYTE)vol&0x7f)>>2)|FM_vol[voice]);
}

void FM_RythmMode(BYTE bool)
{
	WORD data;

	if(bool) data=0xbde0;
	else data=0xbdc0;
	rythm=data;
	FM_Write(data);
}

void FM_RythmOn(BYTE inst)
{
	rythm|=inst;
	FM_Write(rythm);
}

void FM_RythmOff(BYTE inst)
{
	rythm&=(~inst);
	FM_Write(rythm);
}

void FM_KeyOn(BYTE voice)
{
	WORD data;

	data=0xb000+(voice<<8)|FM_key[voice]|0x20;
	FM_Write(data);
}

void FM_KeyOff(BYTE voice)
{
	WORD data;

	data=0xb000+(voice<<8)|FM_key[voice];
	FM_Write(data);
}





/*  ---------------  Mixer  Stuff ------------ */


void MIX_Reset()
{
	asm mov dx,io_addr
	asm add dx,MIX_ADR_OFF
	asm mov al,0
	asm out dx,al
	asm inc dx
	asm out dx,al
}

void MIX_SetInput(BYTE opt)
{
	asm mov dx,io_addr;
	asm add dx,MIX_ADR_OFF;
	asm mov al,MIX_INPUT;
	asm out dx,al;
	asm inc dx;
	asm mov al,opt;
	asm out dx,al;
}

void MIX_SetOutput(BYTE opt)
{
	asm mov dx,io_addr;
	asm add dx,MIX_ADR_OFF;
	asm mov al,MIX_OUTPUT;
	asm out dx,al;
	asm inc dx;
	asm mov al,opt;
	asm out dx,al;
}

void MIX_SetVolume(BYTE reg,BYTE left,BYTE right)
{
	asm mov dx,io_addr
	asm add dx,MIX_ADR_OFF
	asm mov al,reg
	asm out dx,al
	asm inc dx
	asm mov al,left
	asm mov cl,4
	asm shl al,cl
	asm or al,right
	asm out dx,al
}

void MIX_GetVolume(BYTE reg,BYTE *left,BYTE *right)
{
	asm mov dx,io_addr
	asm add dx,MIX_ADR_OFF
	asm mov al,reg
	asm out dx,al
	asm inc dx
	asm in al,dx
	asm mov ah,al
	asm les bx,right
	asm and al,0xf
	asm mov es:[bx],al
	asm mov al,ah
	asm les bx,left
	asm mov cl,4
	asm shr al,cl
	asm mov es:[bx],al
}



/*  ---------------  Midi  Stuff ------------ */



void MIDI_Write(BYTE data)
{
	DSP_Write(DSP_MIDI_WRITE);
	DSP_Write(data);
}

void MIDI_WriteBuf(BYTE *data,int length)
{
	int i;

	for(i=0;i<length;i++) MIDI_Write(data[i]);
}

static void far interrupt midi_int()
{
	asm mov dx,io_addr;   /* read midi code from DSP */
	asm add dx,DSP_READ;
	asm in al,dx;

	asm mov si,rx;        /* write code into buffer */
	asm inc si;
	asm cmp si,midi_buflen; /* make turnaround at buffer limit */
	asm jnz no_turn
	asm mov si,0
no_turn:
	asm mov rx,si;
	asm les bx,midi_recv;
	asm mov es:[bx][si],al

	asm mov dx,io_addr;
	asm add dx,DSP_RSTATUS;
	asm in al,dx;         /* Ack DSP interrupt */

	asm mov al,0x20;
	asm out 0x20,al; /* set EOI to master */
	asm mov bx,intnr
	asm cmp bx,7
	asm jbe end
	asm out 0xa0,al; /* set EOI to slave */

end:
}

WORD  MIDI_ByteAvail()
{
	if(ry<rx) return(midi_buflen-rx+ry);
	else return(ry-rx);
}

BYTE MIDI_GetByte()
{
	if(++ry==midi_buflen) ry=0;
	return(midi_recv[ry]);
}

void MIDI_ReadBuf(WORD count,BYTE *buffer)
{
	int i;

	for(i=0;i<count;i++)
	{
		if(++ry==midi_buflen) ry=0;
		buffer[i]=midi_recv[ry];
	}
	/* not the fastest! this routine has to be improved in the future */
}

int MIDI_Init(BYTE mode,WORD buflen)
{
	midi_mode=mode;
	if(mode==DSP_MIDI_UART && dsp_vers<0x2000) return(FALSE);
	midi_recv=malloc(buflen);
	if(!midi_recv) return(FALSE);
	midi_buflen=buflen;
	rx=ry=0;
	DSP_Write(mode);
	return(TRUE);
}

void MIDI_Remove()
{
	if(midi_mode==DSP_MIDI_READI) DSP_Write(DSP_MIDI_READI);
	else DSP_Reset();
	if(midi_recv) free(midi_recv);
}



/*  ---------------  voc  Stuff ------------ */



int VocPlay(char far *data)
{
	vocptr=data;
	if(strncmp(vocptr,"Creative Voice File\x1a",20) || *((WORD *)vocptr+11)!=(~*((WORD *)vocptr+12)+0x1234))
		return(FALSE);
	vocptr+=*((WORD *)vocptr+10);
	voc_mode=TRUE;
	voc_ext=FALSE;
	voccnt=0;
	VocHandle();
	return(TRUE);
}

void VocStop()
{
	voc_mode=FALSE;
	if(dma_sb_busy) DSP_Write(DSP_HALT_DMA);
}

static void VocHandle()
{
	BYTE tmp;

	while(*vocptr)
	{
		voc_blklen=((DWORD)(*(vocptr+3))<<16)+ *((WORD *)(vocptr+1))+4;
		switch(*vocptr)
		{
			case 1:	if(!voc_ext)
					{
						DSP_Write(DSP_SAMPLE_RATE);
						DSP_Write(*(vocptr+4));
						voc_pmode=*(vocptr+5);
					}
					else
					voc_ext=FALSE;
					Play((char far *)vocptr+6,voc_pmode,voc_blklen-6);
					vocptr+=voc_blklen;
					return;
			case 2: Play((char far *)vocptr+4,voc_pmode,voc_blklen-4);
					vocptr+=voc_blklen;
					return;
			case 3: DSP_Write(DSP_SAMPLE_RATE);
					DSP_Write(*(vocptr+6));
					DSP_Write(DSP_SILENCE);
					DSP_Write(*(vocptr+4));
					DSP_Write(*(vocptr+5));
					vocptr+=7;
					return;
			case 6: vocrem=vocptr+6;
					voccnt=*((WORD *)(vocptr+4));
					vocptr+=6;
				   break;
			case 7: if(voccnt) vocptr=vocrem;
					if(voccnt!=0xffff) voccnt--;
				   break;
			case 8: DSP_Write(DSP_SAMPLE_RATE);
					DSP_Write(*(vocptr+5));
					if(*(vocptr+7)) tmp=MIX_STEREO;
					else tmp=MIX_MONO;
					MIX_SetOutput(tmp);
					voc_pmode=*(vocptr+6);
					voc_ext=TRUE;
					vocptr+=8;
				   break;
		}
	}
	voc_mode=FALSE;
}




/*  ---------------  DSP  Stuff ------------ */



int DSP_Reset()
{
	int i;

	asm mov dx,io_addr;
	asm add dx,DSP_RESET;
	asm mov al,1
	asm out dx,al;

	mcalc(mue3);

	asm mov dx,io_addr;
	asm add dx,DSP_RESET;
	asm mov al,0
	asm out dx,al;

	for(i=0;i<50;i++)
	{
		mcalc(mue3);
		if(DSP_Read()==0xaa) return(TRUE);
	}

	return(FALSE);
}

BYTE DSP_Read()
{
	asm mov dx,io_addr;
	asm add dx,DSP_RSTATUS;
loop:
	asm in al,dx;
	asm test al,0x80;
	asm jz loop

	asm mov dx,io_addr;
	asm add dx,DSP_READ;
	asm in al,dx;
	return(_AL);
}

void DSP_Write(BYTE output)
{
	asm mov dx,io_addr;
	asm add dx,DSP_WSTATUS;
loop:
	asm in al,dx;
	asm test al,0x80;
	asm jnz loop

	asm mov dx,io_addr;
	asm add dx,DSP_WRITE;
	asm mov al,output
	asm out dx,al;
}

int get_sb_env()
{
	char *str;
	int ret;

	str=getenv("BLASTER");
	if(!str) return(FALSE);
	ret=sscanf(str,"A%x I%d D%d T%d",&io_addr,&intnr,&dma_ch,&card_id);
	if(ret!=4 || io_addr<0x210 || io_addr>0x260 || dma_ch!=1 || intnr<2 || intnr>10)
		return(FALSE);
	return(TRUE);
}

void SetRate(DWORD rate)
{
	DWORD val;

	if(rate<4000) return;
	val=256-1000000/rate;
	DSP_Write(DSP_SAMPLE_RATE);
	DSP_Write((BYTE)val);
}

void SetHighRate(DWORD rate)
{
	WORD val;

	if(rate<4000) return;
	val=65536-(WORD)(256000000/rate);
	DSP_Write(DSP_SAMPLE_RATE);
	DSP_Write((BYTE)(val>>8));
}

WORD DSP_GetVersion()
{
	DSP_Write(DSP_GET_VERS);
	return((WORD)DSP_Read()*256+DSP_Read());
}

int Play(char far *data,playmode mode,DWORD length)
{
	return(PlayXMS(far2long(data),mode,length));
}

int PlayXMS(DWORD data,playmode mode,DWORD length)
{
	WORD len;
	BYTE dsp_mode;

	if(dma_sb_busy)
	{
		DSP_Write(DSP_HALT_DMA);  /* halt dma */
		dma_sb_busy=FALSE;
	}
	len=dma_set(data,length,dma_ch,DMA_OUT|DMA_SINGLE|DMA_AUTO)-1; /* set dma */

	DSP_high_mode=0;
	switch(mode)
	{
		case bit8:
				dsp_mode=DSP_DMA_8BIT;
				DSP_intr_mode=DSP_DMA_8BIT;
			   break;
		case bit4:
				dsp_mode=DSP_DMA_4BIT_REF;
				DSP_intr_mode=DSP_DMA_4BIT;
			   break;
		case bit26:
				dsp_mode=DSP_DMA_26BIT_REF;
				DSP_intr_mode=DSP_DMA_26BIT;
			   break;
		case bit2:
				dsp_mode=DSP_DMA_2BIT_REF;
				DSP_intr_mode=DSP_DMA_2BIT;
			   break;
		case high:
				dsp_mode=DSP_BLOCK_SIZE;
				DSP_intr_mode=DSP_BLOCK_SIZE;
				DSP_high_mode=DSP_DMA_HIGHSPEED;
	}
	dma_sb_busy=TRUE;
	DSP_Write(dsp_mode);
	DSP_Write((BYTE)len);   /* write length to DSP */
	DSP_Write((BYTE)(len>>8));
	if(DSP_high_mode) DSP_Write(DSP_DMA_HIGHSPEED);

	return(TRUE);
}

int Sample(char far *data,playmode mode,DWORD length)
{
	WORD len;
	BYTE dsp_mode;

	if(dma_sb_busy)
	{
		DSP_Write(DSP_HALT_DMA);  /* halt dma */
		dma_sb_busy=FALSE;
	}
	len=dma_set(far2long(data),length,dma_ch,DMA_IN|DMA_SINGLE|DMA_AUTO)-1; /* set dma */

	DSP_high_mode=0;
	switch(mode)
	{
		case bit8:
				dsp_mode=DSP_DMA_ADC;
				DSP_intr_mode=DSP_DMA_ADC;
			   break;
		case high:
				dsp_mode=DSP_BLOCK_SIZE;
				DSP_intr_mode=DSP_BLOCK_SIZE;
				DSP_high_mode=DSP_DMA_ADC_HIGHSPEED;
	}
	dma_sb_busy=TRUE;
	DSP_Write(dsp_mode);
	DSP_Write((BYTE)len);   /* write length to DSP */
	DSP_Write((BYTE)(len>>8));
	if(DSP_high_mode) DSP_Write(DSP_DMA_ADC_HIGHSPEED);

	return(TRUE);
}


static void far interrupt sb_int()
{
	WORD length;

	asm mov dx,io_addr;
	asm add dx,DSP_RSTATUS;
	asm in al,dx;         /* Ack DSP interrupt */

	if(dma_len(dma_ch))                /* if bytes left reprogram DSP */
	{
		length=dma_next(dma_ch)-1;  /* check for another dma block */
		DSP_Write(DSP_intr_mode);   /* set DSP mode */
		DSP_Write((BYTE)length);
		DSP_Write((BYTE)(length>>8));
		if(DSP_high_mode) DSP_Write(DSP_high_mode);
	}
	else
	{
		dma_sb_busy=FALSE;
		if(voc_mode) VocHandle();
	}

	asm mov al,0x20;
	asm out 0x20,al; /* set EOI */
	asm mov bx,intnr
	asm cmp bx,7
	asm jbe end
	asm out 0xa0,al; /* set EOI */

end:
}



/*  ---------------  Misc.  Stuff ------------ */


int CardCheck()
{
	int ret=0;

	if(FM_Detect()) ret|=FM_DETECT;
	if(DSP_Reset()) ret|=DSP_DETECT;
	return(ret);
}

static void far interrupt testn_int()
{
	tst_cnt++;

	asm mov dx,io_addr;
	asm add dx,DSP_RSTATUS;
	asm in al,dx;         /* Ack DSP interrupt */

	asm mov al,0x20;
	asm out 0x20,al; /* set EOI */
	asm mov bx,intnr
	asm cmp bx,7
	asm jbe end
	asm out 0xa0,al; /* set EOI */

end:
}

static BYTE scan_dma()
{
	BYTE dma1,dma2,dma1r,dma2r,cnt;

	DSP_Write(DSP_SPKR_OFF);
	SetRate(22000);
	DSP_Write(DSP_DMA_8BIT);
	DSP_Write(10);

	asm cli

	asm in al,8
	asm and al,0xe0
	asm mov dma1,al
	asm in al,0xd0
	asm and al,0xf0
	asm mov dma2,al

	DSP_Write(0);

	asm mov cx,60000
loop1:
	asm in al,8
	asm and al,0xe0
	asm mov dma1r,al
	asm cmp al,dma1
	asm jnz req

	asm in al,0xd0
	asm and al,0xf0
	asm mov dma2r,al
	asm cmp al,dma2
	asm jnz req

	asm loop loop1
req:
	asm sti
	DSP_Reset(); /* cause our DSP it's a little bit confused */

	if(dma1!=dma1r)
	{
		cnt=0;
		dma1r=dma1r&(~dma1);
		while(dma1r>>=1) cnt++;
		return(cnt-4);
	}
	if(dma2!=dma2r)
	{
		cnt=0;
		dma2r=dma2r&(~dma2);
		while(dma2r>>=1) cnt++;
		return(cnt-4);
	}
	return(0xff);  /* no dma request occured ???? */
}

static int test_int()
{
	int i;
	BYTE int1,int2;

	tst_cnt=0;
	orgint=getvect(int2vect(intnr));

	asm in al,0x21;   /* save org master intr settings */
	asm mov int1,al;

	asm in al,0xa1;   /* save org slave intr settings */
	asm mov int2,al;

	asm mov al,0xfe;
	asm cli;
	asm out 0x21,al;  /* disable ALL intr */
	asm mov al,0xff
	asm out 0xa1,al;
	asm sti;

	enable_int(intnr);
	setvect(int2vect(intnr),testn_int);

	DSP_Write(DSP_INVOKE_INTR);  /* still magic -- make DSP interrupt? */

	for(i=0;i<30000;i++) if(tst_cnt) break;

	asm cli;
	asm mov al,int1;
	asm out 0x21,al;  /* restore org master intr */

	asm mov al,int2;  /* restore org slave intr */
	asm out 0xa1,al;
	asm sti;
	setvect(int2vect(intnr),orgint);

	if(i==30000) return(FALSE);
	else return(TRUE);
}

static int scan_int()
{
	int i;

	if(test_int()) return(intnr);
	for(i=0;i<5;i++)
	{
		intnr=intrx[i];
		if(test_int()) return(i);
	}
	return(0);
}

static cardtype CheckHard()
{
	int ret,ret2,ret3;

	ret=DSP_Reset();
	if(ret)
	{
		if(!scan_int()) return(none);

		fm_addr=io_addr+FM_BOTH_OFF;
		if(!FM_Detect()) return(none); /* no fm? -> damaged! */

		fm_both=fm_addr;
		fm_addr=io_addr+FM_RIGHT_OFF;
		fm_right=fm_addr;
		ret3=FM_Detect();
		fm_addr=fm_both;

		if(ret3)
		{
			wh_card=sbpro;
			fm_left=io_addr+FM_LEFT_OFF;
		}
		else wh_card=sb20;
		return(wh_card);
	}
	return(nodsp);
}

cardtype WhichCard()
{
	cardtype cret;
	int i;

	if(get_sb_env()) cret=CheckHard();
	if(cret!=nodsp) return(cret);

	intnr=7;
	for(i=0;i<6;i++)
	{
		io_addr=ioaddr[i];

		cret=CheckHard();
		if(cret!=nodsp) return(cret);
	}

	fm_addr=0x388;
	if(FM_Detect())
	{
		fm_both=fm_addr;
		wh_card=adlib;
		return(adlib);
	}

	return(none);
}

int SB_Setup()
{
	int ret,ret2;

	InitT2();  /* init Timer 2 */
	measure(); /* time loop factor */
	mue3=mcalc(3);   /* calc val for 3 micro sec delay */
	mue23=mcalc(23);   /* calc val for 23 micro sec delay */

	dma_sb_busy=FALSE;
	voc_mode=FALSE;
	WhichCard();
	if(wh_card==none) return(FALSE);
	if(wh_card==sb20 || wh_card==sbpro)
	{
		dma_ch=scan_dma();
		if(dma_ch==0xff) return(FALSE);
		dsp_vers=DSP_GetVersion();
		DSP_Write(DSP_SPKR_ON);
	}
	return(TRUE);
}


void SB_SetVect(vect which)
{
	orgint=getvect(int2vect(intnr));
	if(which==midi) setvect(int2vect(intnr),midi_int);
	setvect(int2vect(intnr),sb_int); /* set vector to our routine */
	enable_int(intnr);       /* enable sb interrupt */
}

void SB_RemoveVect()
{
	disable_int(intnr);   /* disable sb interrupt */
	setvect(int2vect(intnr),orgint);    /* restore org intr vector */
}

