#include <stdio.h>
#include <malloc.h>

int main ()
{
    int test, t, i, k, days, parties, param, gap, loss, *ara, count;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {

        scanf("%d%d", &days, &parties);

        ara=(int)calloc(days, sizeof(int));

        count=0;
        for(i=0; i<days; i++) {
            count++;
            if (count==6) ara[i]=2;
            else if (count==7) { ara[i]=2; count=0; }

        }
        for(i=1; i<=parties; i++) {
            scanf("%d", &param);
            gap=param;
            for(k=0; k<days; k++) if ((k+1)%gap==0 && ara[k]!=2) ara[k]=1;
        }
        loss=0;
        for(i=0; i<days; i++) if (ara[i]==1) loss++;

        printf("%d\n", loss);
    }

    return 0;
}
