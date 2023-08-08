#include "stdio.h"
#include "input.h"

int main()
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    int cnt = 0;
    int ECNT = 0;
    int cntMax = 0;
    int EcntMax = 0;
    unsigned char T = 20;
    for(int i=0; i<240*320; i++)
    {
        R = R_input[i];
        G = G_input[i];
        B = B_input[i];
        cnt = 0;
        ECNT = 0;
        for(int j=0; j<240*320; j++)
        {
            if(R >= R_input[j] - T && R <= R_input[j] + T && G >= G_input[j] - T && G <= G_input[j] + T && B >= B_input[j] - T && B <= B_input[j] + T)
                cnt++;
                if(R == R_input[j]  && G == G_input[j] && B == B_input[j])
                    ECNT++;
        }
        if(cnt > cntMax)
        {
            cntMax = cnt;
            EcntMax = ECNT;
            printf("%d %d %d -> %d, %d\n", R, G, B, cnt, EcntMax);
        }
    }

}