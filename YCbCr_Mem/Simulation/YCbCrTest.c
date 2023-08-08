#include "YCbCr.c"  //in HLS comment this line
#include "stdio.h"
#include "input.h"

int main()
{
    //struct RGB data = { 82, 0, 87 };
    int cnt =0;
    unsigned char R;
    unsigned char G;
    unsigned char B;
    FILE *fp;
    unsigned char Y_out[240*320];
    unsigned char Cb_out[240*320];
    unsigned char Cr_out[240*320];
    struct YCbCr value;
    for(int i=0; i<240*320; i++)
    {
        R = R_input[i];
        G = G_input[i];
        B = B_input[i];
        value = RGBToYCbCr(R, G, B);
        Y_out[i] = value.Y;
        Cb_out[i] = value.Cb;
        Cr_out[i] = value.Cr;
        if(value.f == 1)
            cnt++;
        //printf("%d %d %d --> %d %d %d\n", R, G, B, value.Y, value.Cb, value.Cr);
    }
    //printf("%d %d %d --> %d %d %d\n", R_input[4800], G_input[4800], B_input[4800],Y_out[4800], Cb_out[4800], Cr_out[4800]);
    printf("%d \n",cnt);
    fp = fopen("Y_result.txt", "w");
    for(int i = 0; i < 240; i++)
    {
        for(int j = 0; j < 320; j++)
		    fprintf(fp, "%d ", Y_out[i*WIDTH+j]);
        fprintf(fp, "\n");
	}
    fclose(fp);

    fp = fopen("Cb_result.txt", "w");
    for(int i = 0; i < 240; i++)
    {
        for(int j = 0; j < 320; j++)
		    fprintf(fp, "%d ", Cb_out[i*WIDTH+j]);
        fprintf(fp, "\n");
    }
	fclose(fp);

    fp = fopen("Cr_result.txt", "w");
    for(int i = 0; i < 240; i++)
    {
        for(int j = 0; j < 320; j++)
		    fprintf(fp, "%d ", Cr_out[i*WIDTH+j]);
        fprintf(fp, "\n");
    }
	fclose(fp);
    
    printf("Done!");
    return 0;
}