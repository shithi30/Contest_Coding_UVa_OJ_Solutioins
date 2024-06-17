#include <stdio.h>
int main ()
{
    long long int cuts, pcs, i;
    while (scanf("%lld", &cuts)==1) {
        if (cuts<0) break;
        else if (cuts==0) { pcs=1; printf("%lld\n",pcs); }
        else if (cuts==1) { pcs=2; printf("%lld\n",pcs); }
        else if (cuts==2) { pcs=4; printf("%lld\n",pcs); }
        else {
            pcs=4;
            for (i=3; i<=cuts; i++) {
                pcs=(pcs-i)+(2*i);
            }
            printf("%lld\n", pcs);
        }
    }
    return 0;
}
