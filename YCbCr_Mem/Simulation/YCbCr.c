#include "YCbCr.h"



struct YCbCr RGBToYCbCr(unsigned char R, unsigned char G, unsigned char B) {
	struct YCbCr ycbcr;
	unsigned char Ymem = 62;
	unsigned char Cbmem = 133;
	unsigned char Crmem = 123;


	if (R<R_MEM+TH && R>R_MEM-TH && G<G_MEM+TH && G>G_MEM-TH && B<B_MEM+TH && B>B_MEM-TH)
	{	
		ycbcr.Y = Ymem;
		ycbcr.Cb = Cbmem;
		ycbcr.Cr = Crmem;
		ycbcr.f = 1;
	}
	else
	{
		ycbcr.Y = (0.257 * R) + (0.504 * G) + (0.098 * B) + 16;
		ycbcr.Cb = ((-0.148) * R) - (0.291 * G) + (0.439 * B) + 128;
		ycbcr.Cr = (0.439 * R) - (0.368 * G) - (0.071 * B) + 128;
		ycbcr.f = 0;
	}
	return ycbcr;
}


