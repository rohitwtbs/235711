
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
#include "timerx.h"

#define CINTNO 0
#define SLAVEPIC 2
#define RTCINTNO 8

typedef unsigned char BYTE;
typedef unsigned int  WORD;

static void far interrupt (*orgtick)();
static void far interrupt (*orgrtc)();
static void far (*call_func)();
static void far (*rtc_func)();
static WORD timer_val,timer_hold,timer_diff,mue999;
static WORD timadd,timsum;

/* Joystick routines are following */

WORD tax,tay,tbx,tby; /* values of potentiometer */
WORD ba1,ba2,bb1,bb2; /* button values; bit set = pressed */


/* ReadTJoy reads the potentiometer values from the joysticks */
/* the argument which defines which of the 4 potis to read    */
/* the 1st 4 bits correspond to the potis to read if bit set  */
/* a value of 0 in tax,..tby means no joystick connected      */

void ReadTJoy(BYTE which)
{
	asm mov tax,0;  /* init values */
	asm mov tay,0;
	asm mov tbx,0;
	asm mov tby,0;

	asm mov dx,0x201; /* joyport address */
	asm out dx,al;

	asm mov al,0x80;  /* latch timer 2 */
	asm out 0x43,al;  /* save value in bx */
	asm in al,0x42;
	asm mov bl,al;
	asm in al,0x42;
	asm mov bh,al;

joyloop:
	asm in al,dx;
	asm mov cl,al;    /* read joyport bits to cl */

	asm test cl,0x1;  /* timer bit set? */
	asm jnz notax;
	asm test tax,0xffff; /* value already got? */
	asm jz getax;
notax:
	asm test cl,0x2;
	asm jnz notay;
	asm test tay,0xffff;
	asm jz getay;
notay:
	asm test cl,0x4;
	asm jnz notbx;
	asm test tbx,0xffff;
	asm jz getbx;
notbx:
	asm test cl,0x8;
	asm jnz notby;
	asm test tby,0xffff;
	asm jz getby;
notby:

	asm test cl,which;
	asm jz end;

	asm mov al,0x80;
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm sub ax,bx;
	asm neg ax;
	asm cmp ax,5000;  /* leave routine after 5000 CLK */
	asm jg end;
	asm jmp joyloop;

getax:
	asm mov al,0x80;
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm sub ax,bx;
	asm neg ax;
	asm mov tax,ax;
	asm jmp joyloop;

getay:
	asm mov al,0x80;
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm sub ax,bx;
	asm neg ax;
	asm mov tay,ax;
	asm jmp joyloop;

getbx:
	asm mov al,0x80;
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm sub ax,bx;
	asm neg ax;
	asm mov tbx,ax;
	asm jmp joyloop;

getby:
	asm mov al,0x80;
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm sub ax,bx;
	asm neg ax;
	asm mov tby,ax;
	asm jmp joyloop;


end:
}

void ReadBJoy()
{
	asm mov dx,0x201;
	asm in al,dx;
	asm neg al;
	asm mov bh,0;

	asm mov bl,al;
	asm and bx,0x10;
	asm mov ba1,bx;

	asm mov bl,al;
	asm and bx,0x20;
	asm mov ba2,bx;

	asm mov bl,al;
	asm and bx,0x40;
	asm mov bb1,bx;

	asm mov bl,al;
	asm and bx,0x80;
	asm mov bb2,bx;
}

/* same as ReadTJoy, but uses no timer */
/* a little bit inaccurate and machine dependant */

void ReadTJoy2(BYTE which)
{
	asm mov tax,0;  /* init values */
	asm mov tay,0;
	asm mov tbx,0;
	asm mov tby,0;

	asm mov dx,0x201; /* joyport address */
	asm out dx,al;

	asm mov cx,0;

joyloop:
	asm in al,dx;

	asm test al,0x1;     /* timer bit set? */
	asm jnz notax;
	asm test tax,0xffff; /* value already got? */
	asm jnz notax2;
	asm jmp getax;
notax:
	asm nop
	asm nop
	asm nop
notax2:
	asm test al,0x2;
	asm jnz notay;
	asm test tay,0xffff;
	asm jnz notay2;
	asm jmp getay;
notay:
	asm nop
	asm nop
	asm nop
notay2:
	asm test al,0x4;
	asm jnz notbx;
	asm test tbx,0xffff;
	asm jnz notbx2;
	asm jmp getbx;
notbx:
	asm nop
	asm nop
	asm nop
notbx2:
	asm test al,0x8;
	asm jnz notby;
	asm test tby,0xffff;
	asm jnz notby2;
	asm jmp getby;
notby:
	asm nop
	asm nop
	asm nop
notby2:

	asm test al,which;
	asm jz end;

	asm inc cx;
	asm cmp cx,5000;  /* leave routine after 5000 inc cx */
	asm jg end;
	asm jmp joyloop;

getax:
	asm mov tax,cx;
	asm jmp joyloop;

getay:
	asm mov tay,cx;
	asm jmp joyloop;

getbx:
	asm mov tbx,cx;
	asm jmp joyloop;

getby:
	asm mov tby,cx;
	asm jmp joyloop;


end:
}

/* --------------------------------------------------- */

/* timerX routines are following */

void InitT2()
{
	asm in al,0x61   /* no signal on speaker! */
	asm and al,0xfd
	asm or  al,1
	asm out 0x61,al

	asm mov al,0xb4  /* program timer 2 with modus 2 */
	asm out 0x43,al  /* and counter value of 0 (2^16)*/
	asm mov al,0
	asm out 0x42,al
	asm out 0x42,al
}

void timer_on()
{
	asm mov al,0x80;  /* latch timer 2 */
	asm out 0x43,al;  /* save value in timer_hold */
	asm in al,0x42;
	asm mov bl,al;
	asm in al,0x42;
	asm mov bh,al;
	asm mov timer_hold,bx;
}

WORD timer_off()
{
	asm mov al,0x80; /* latch timer 2 */
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm mov bx,timer_hold;
	asm sub ax,bx;
	asm neg ax;
	asm mov timer_diff,ax; /* calc timer_hold - ax to timer_diff */
	return(_AX);
}

WORD to_micro(WORD clk)
{
    return(clk*838/1000);    
}

void clkdelay(WORD clicks)
{
	asm mov al,0x80;  /* latch timer 2 */
	asm out 0x43,al;  /* save value in bx */
	asm in al,0x42;
	asm mov bl,al;
	asm in al,0x42;
	asm mov bh,al;
loop:
	asm mov al,0x80;
	asm out 0x43,al;
	asm in al,0x42;
	asm mov ah,al;
	asm in al,0x42;
	asm xchg ah,al;
	asm sub ax,bx;
	asm neg ax;
	asm cmp ax,clicks;  /* leave routine after click CLK's */
	asm jle loop;
}

void measure()
{
	timer_on();

	asm cli
	asm mov cx,10000  /* internal test loop */
loop1:
	asm loop loop1

	timer_off();
	asm sti
	timer_val=timer_diff;

	mue999=mcalc(999); /* calc for msdelay */
}

void mdelay(WORD delay)
{
	asm mov cx,delay
 loop1:
	asm loop loop1
}

void msdelay(WORD delay)
{
	WORD i;

	for(i=0;i<delay;i++) mdelay(mue999); /* only 999 cause of fnctn call */
}

WORD mcalc(WORD micro)
{
	return((long)micro*10000L/timer_val*1000/838);
}

WORD vbl_measure()
{
	asm mov dx,0x3da

loop1:
	asm in al,dx;  /* wait for end vbl */
	asm test al,8;
	asm jnz loop1;

loop2:             /* wait for vbl */
	asm in al,dx;
	asm test al,8;
	asm jz loop2;

	asm cli
	timer_on();

loop3:
	asm in al,dx;  /* wait for end vbl */
	asm test al,8;
	asm jnz loop3;

loop4:             /* wait for vbl */
	asm in al,dx;
	asm test al,8;
	asm jz loop4;

	timer_off();
	asm sti
	return(timer_diff);
}

/* --------------- timer 0 stuff ----------------- */

static void interrupt timerint()
{
	call_func();

	if(timsum<100)
	{
		timsum+=timadd;
		orgtick();
	}
	else
	{
		asm mov al,0x20;
		asm out 0x20,al;
	}
	timsum-=100;
}

void Install_Timer0(WORD period,void far (*func)())
{
	if(period<120) return;  /* timer calc's will fail */
	if(!func) return;       /* no valid func ptr */
	call_func=func;
	timadd= (WORD)(6553600L/period);
	timsum=0;

	asm mov al,0x36  /* program timer 0 with modus 3 */
	asm out 0x43,al  /* and counter value of period  */
	asm mov ax,period
	asm out 0x40,al
	asm mov al,ah
	asm out 0x40,al

	enable_int(CINTNO); /* just in case... */

	orgtick= getvect(int2vect(CINTNO));   // Install 18.2 Hertz Interrupt
	setvect(int2vect(CINTNO),timerint);
}

void Remove_Timer0()
{
	asm mov al,0x36  /* program timer 0 with modus 3 */
	asm out 0x43,al  /* and counter value of 0 (2^16)*/
	asm mov al,0
	asm out 0x40,al
	asm out 0x40,al
	setvect(int2vect(CINTNO),orgtick);
}

/* --------------- Real Time Clock intr -----------*/

static void interrupt rtc_int()
{
	asm cli

	asm mov al,0x20
	asm out 0xa0,al
	asm out 0x20,al	 /* send EOI to both intr controllers */

	asm sti

	asm mov al,0xc
	asm out 0x70,al
	asm in  al,0x71	/* read register c of rtc, to determine intr source & acknoledge intr */

	if(_AL & 0x40)  /* periodical rtc interrupt ? */
	{
		rtc_func();
	}
}

void Install_RTC(WORD hertz,void far (*func)())
{
	WORD calc;
	BYTE cnt;

	if(hertz>8192) return;  /* rtc will only allow up to 8192hz */
	if(!func) return;       /* no valid func ptr */
	rtc_func=func;

	calc=(long)65536L/hertz;
	cnt=0;
	while(calc>>=1) cnt++;

	orgrtc= getvect(int2vect(RTCINTNO));
	setvect(int2vect(RTCINTNO),rtc_int);


	asm cli
	enable_int(SLAVEPIC);
	enable_int(RTCINTNO);

	asm mov al,0xa
	asm out 0x70,al
	asm in al,0x71
	asm and al,0xf0
	asm or  al,cnt
	asm out 0x71,al

	asm mov al,0xc
	asm out 0x70,al
	asm mov al,0x0
	asm out 0x71,al

	asm mov al,0xb
	asm out 0x70,al
	asm in al,0x71
	asm or  al,0x40
	asm out 0x71,al
	asm sti
}

void Remove_RTC()
{
	asm cli
	setvect(int2vect(RTCINTNO),orgrtc);
	asm mov al,0xb		 /* remove setting of periodical intr */
	asm out 0x70,al
	asm in al,0x71
	asm and  al,0x0f
	asm out 0x71,al
	asm sti
	/* do not disable in intr controller because their could be a bios routine */
}

BYTE int2vect(BYTE intnr)
{
	if(intnr>7) return(intnr+0x68);
	else return(intnr+8);
}

void enable_int(BYTE nr)
{
	if(nr>7) /* use 2nd intr controller? */
	{
		asm in al,0xa1;
		asm mov cl,nr;
        asm sub cl,8
		asm mov bl,1;
		asm shl bl,cl;  /* calc correct mask */
		asm not bl;
		asm and al,bl;
		asm out 0xa1,al;
	}
	else
	{
		asm in al,0x21;
		asm mov cl,nr;
		asm mov bl,1;
		asm shl bl,cl; /* calc correct mask */
		asm not bl;
		asm and al,bl;
		asm out 0x21,al;
	}
}

void disable_int(BYTE nr)
{
	if(nr>7)
	{
		asm in al,0xa1;	  /* use 2nd intr controller? */
		asm mov cl,nr;
		asm sub cl,8
		asm mov bl,1;
		asm shl bl,cl;    /* calc correct mask */
		asm or al,bl;
		asm out 0xa1,al;
	}
	else
	{
		asm in al,0x21;
		asm mov cl,nr;
		asm mov bl,1;
		asm shl bl,cl;    /* calc correct mask */
		asm or al,bl;
		asm out 0x21,al;
	}
}
