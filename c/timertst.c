#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include "timerx.h"

typedef unsigned int WORD;

volatile WORD cnt;

/* timerx example program */
/* makes nothing important, just an example how to use */

void far inc()  /* func ptr of this func is given to Install_Timer0 */
{
	cnt++;
}

void main()
{
	WORD lp,vbl;

	InitT2();            /* first initialize timer 2 */
	vbl=vbl_measure();   /* store in vbl nr of clk's between 2 vbl's '*/
	measure();           /* measure nr of clk's in an empty loop */
	lp=mcalc(100);       /* store in lp loop factor for 100 micro sec */
	mdelay(lp);          /* wait 100 micro sec */
	printf("clk:%u vbl:%u\n",lp,vbl);
	Install_RTC(2,inc); /* set timer 0 interval to one vertical blank */
	while(!kbhit())
	{
		ReadTJoy(3); /* read x & y values of first joystick */
		ReadBJoy();  /* read buttons */
		printf("cnt:%u ax:%u ay%u button1:%u button2:%u\n",cnt,tax,tay,ba1,ba2);
	}
	Remove_RTC();         /* reset to old values */
}
