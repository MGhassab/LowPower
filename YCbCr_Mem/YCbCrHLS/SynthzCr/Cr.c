#include "Cr.h"



unsigned char Cr(unsigned char R, unsigned char G, unsigned char B) {
	unsigned char Out;
	// unsigned char Outmem = 62;  //Y
	// unsigned char Outmem = 133; //Cb
	 unsigned char Outmem = 123; //Cr
	if (R<R_MEM+TH && R>R_MEM-TH && G<G_MEM+TH && G>G_MEM-TH && B<B_MEM+TH && B>B_MEM-TH)
	{	Out = Outmem;
	}
	else
	{
		// Out = (0.257 * R) + (0.504 * G) + (0.098 * B) + 16;
		// Out = ((-0.148) * R) - (0.291 * G) + (0.439 * B) + 128;
		 Out = (0.439 * R) - (0.368 * G) - (0.071 * B) + 128;
	}
	return Out;
}


