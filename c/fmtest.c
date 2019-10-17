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
#include "dmalib.h"
#include "timerx.h"

char	  inst[4][11] =
	{
		{   0x021,0x011,0x04C,0x000,0x0F1,0x0F2,0x063,0x072,
			0x000,0x000,0x004},

		{   0x0A5,0x0B1,0x0D2,0x080,0x081,0x0F1,0x003,0x005,
			0x000,0x000,0x002},

		{   0x072,0x062,0x01C,0x005,0x051,0x052,0x003,0x013,
			0x000,0x000,0x00E},

		{   0x011,0x001,0x08A,0x040,0x0F1,0x0F1,0x011,0x0B3,
			0x000,0x000,0x006}                                };


void PlayTest ()
{
	unsigned int i,j;
	int note,instn,voice;



	static BYTE note_num[] = {60,62,64,65,67,69,71,72,74};


	for(voice=0;voice<1;voice++)
	{
		for ( instn= 0; instn < 4; instn++ )
		{
			FM_SetVoice ( 0,inst[instn]) ;
			FM_SetVol(voice,0x60);

			for ( note=0; note < 9; note++ )
			{
				FM_SetNote ( voice, note_num[note]) ;
				FM_KeyOn(voice);
				msdelay(400);
				FM_KeyOff(voice);
			}
		}
	}
}

void main()
{
	SB_Setup();

	PlayTest();
}

