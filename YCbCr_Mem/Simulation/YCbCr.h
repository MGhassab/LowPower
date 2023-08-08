#ifndef _YCBCR_H_
#define _YCBCR_H_

#include "stdio.h"

#define HEIGHT 240
#define WIDTH 320
#define R_MEM 46
#define G_MEM 56
#define B_MEM 65
#define TH 20

struct YCbCr
{
	unsigned char Y;
	unsigned char Cb;
	unsigned char Cr;
	int f;
};


struct YCbCr RGBToYCbCr(unsigned char R, unsigned char G, unsigned char B);

#endif