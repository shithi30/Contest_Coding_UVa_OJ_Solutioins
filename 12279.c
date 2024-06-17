#include <stdio.h>

int main ()
{
    int events, t, sum, num, test=0;

    for ( ; ; ) {
        scanf("%d", &events);
        if (events==0) break;
        sum=0; test=test+1;

        for(t=1; t<=events; t++) {
            scanf("%d", &num);
            if (num!=0) sum=sum+1;
            else sum=sum-1;
        }
        printf("Case %d: %d\n", test, sum);
    }
    return 0;
}
