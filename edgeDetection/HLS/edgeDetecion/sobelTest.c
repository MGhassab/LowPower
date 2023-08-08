#include "stdio.h"
#include "input.h"

int main()
{
    FILE *fp;
    int retval=0;
    unsigned char out1[512*512];
    sobel_filter(elaine_512_input, out1);

    fp = fopen("result.dat", "w");
    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
		   fprintf(fp, "%d ", out1[i*512+j]);
        }
        //fprintf(fp, "\n");
	}
	fclose(fp);


    	 // Compare the results file with the golden results
	 retval = system("diff --brief -w result.dat resultgolden.dat");
	 if (retval != 0) {
	 	printf("Test failed  !!!\n");
	 	retval=1;
	 } else {
	 	printf("Test passed !\n");
   }

	 // Return 0 if the test passes
  return 0;
}
