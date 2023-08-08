#include "stdio.h"
#include "testBench512.h"
#include "sobel.c"

int main()
{
    FILE *fp;
    int retval=0;
    unsigned char out1[512*512];
    sobel_filter(elaine_512_input, out1);

    fp = fopen("result.txt", "w");
    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
		   fprintf(fp, "%d ", out1[i*512+j]);
        }
        fprintf(fp, "\n");
	}
	fclose(fp);
  return 0;
}
