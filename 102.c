#include <stdio.h>

int main ()
{
    int i, bcg, bgc, cbg, cgb, gbc, gcb, min;
    int ara[9], bins[6];

    while(scanf("%d", &ara[0])==1) {
        for(i=1; i<9; i++) scanf("%d", &ara[i]);

        bins[0]=bcg=ara[3]+ara[6]+ara[2]+ara[8]+ara[1]+ara[4];
        bins[1]=bgc=ara[3]+ara[6]+ara[1]+ara[7]+ara[5]+ara[2];
        bins[2]=cbg=ara[5]+ara[8]+ara[0]+ara[6]+ara[4]+ara[1];
        bins[3]=cgb=ara[5]+ara[8]+ara[1]+ara[7]+ara[3]+ara[0];
        bins[4]=gbc=ara[4]+ara[7]+ara[0]+ara[6]+ara[5]+ara[2];
        bins[5]=gcb=ara[4]+ara[7]+ara[2]+ara[8]+ara[3]+ara[0];

        min=bins[0];
        for(i=0; i<6; i++) if (bins[i]<min) min=bins[i];

        for (i=0; i<6; i++) if (bins[i]==min) break;

        if (i==0) printf("BCG %d\n", min);
        else if (i==1) printf("BGC %d\n", min);
        else if (i==2) printf("CBG %d\n", min);
        else if (i==3) printf("CGB %d\n", min);
        else if (i==4) printf("GBC %d\n", min);
        else if (i==5) printf("GCB %d\n", min);
    }
    return 0;
}
