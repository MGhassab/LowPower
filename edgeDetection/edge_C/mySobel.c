#define HEIGHT 256
#define WIDTH 256
#include <stdio.h>
#include "testBench16.h"
#include "testBench32.h"
#include "testBench64.h"
#include "testBench256.h"
#include "testBench512.h"


void sobel_filter(unsigned char in[HEIGHT*WIDTH],
                  unsigned char out[HEIGHT*WIDTH]) {
    int cnt=0;
    int gx_sum = 0;
    int gy_sum = 0;
    for(int i = 1; i < HEIGHT-1; i++){
        for(int j = 1; j < WIDTH-1; j++){
            gx_sum = 4*in[(i)*WIDTH+(j)] - in[(i-1)*WIDTH+(j)] - in[(i)*WIDTH+(j-1)] - in[(i)*WIDTH+(j+1)] - in[(i+1)*WIDTH+(j)];
            gx_sum = (gx_sum < 0) ? -gx_sum : gx_sum;
            out[i*WIDTH+j] = gx_sum;
            out[i*WIDTH+j] = (out[i*WIDTH+j] > 255) ? 255 : out[i*WIDTH+j];
            //printf("%d ",  in[i*WIDTH+j]);
        }
        //printf("\n");
    }
}

int main()
{
    FILE *fp;
    unsigned char in[HEIGHT*WIDTH], out[HEIGHT*WIDTH];
    sobel_filter(elaine_256_input, out); /////////////////////////

    fp = fopen("result256.txt", "w");   ///////////////////////////
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
		    fprintf(fp, "%d", out[i*WIDTH+j]);
            if(j != WIDTH-1)
                fprintf(fp," ");
        }
        if(i != HEIGHT-1)
            fprintf(fp, "\n");
	}
	fclose(fp);
    printf("Done!");
    return 1;
}