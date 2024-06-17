#include <stdio.h>

int main ()
{
    int test, t, rad, tlx, tly, blx, bly, brx, bry, trx, ytr;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {

        scanf("%d", &rad);

        tlx=-rad*9/4;
        tly=rad*3/2;

        blx=tlx;
        bly=-tly;

        bry=bly;
        brx=rad*11/4;

        trx=brx;
        ytr=-bry;

        printf("Case %d:\n", t);
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", tlx, tly, trx, ytr, brx, bry, blx, bly);
    }

    return 0;
}
