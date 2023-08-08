//#include "Cr.c"  //in HLS comment this line
#include "stdio.h"
#include "input.h"

int main()
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char OUT;

    R = R_input[0];
    G = R_input[1];
    B = R_input[2];
    OUT = Cr(R, G, B);
    printf("%d %d %d --> %d\n", R, G, B, OUT);
    return 0;
}
