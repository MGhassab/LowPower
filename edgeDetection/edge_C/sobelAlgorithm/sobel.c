#include "sobel.h"

void sobel_filter(unsigned char in[512*512], unsigned char out[512*512]) {
	int gx_sum = 0;
    int gy_sum = 0;
    for(int i = 1; i < 512-1; i++){
        for(int j = 1; j < 512-1; j++){
            gx_sum = - in[(i-1)*512+(j-1)] - 2*in[(i)*512+(j-1)] - in[(i+1)*512+(j-1)] + in[(i-1)*512+(j+1)] + 2*in[(i)*512+(j+1)] + in[(i+1)*512+(j+1)];
            gy_sum =   in[(i-1)*512+(j-1)] + 2*in[(i-1)*512+(j)] + in[(i-1)*512+(j+1)] - in[(i+1)*512+(j-1)] - 2*in[(i+1)*512+(j)] - in[(i+1)*512+(j+1)];
            gx_sum = (gx_sum < 0) ? -gx_sum : gx_sum;
            gy_sum = (gy_sum < 0) ? -gy_sum : gy_sum;
            out[i*512+j] = gx_sum + gy_sum;
            out[i*512+j] = (out[i*512+j] > 255) ? 255 : out[i*512+j];
            //printf("%d ",  out[i*WIDTH+j]);
        }
        //printf("\n");
    }
}
