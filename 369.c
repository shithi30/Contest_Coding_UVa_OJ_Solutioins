#include <stdio.h>

int main ()
{
    long long int n, r, big, small, up[200], down[200], num, denom, i, j, k, l;

    while (scanf("%lld%lld", &n, &r)==2) {

        if (n==0 && r==0) break;

        big=(n-r>r)? n-r : r;
        small=(n-r>r)? r : n-r;

        j=0;
        for(i=big+1; i<=n; i++) up[j++]=i;

        k=0;
        for(i=1; i<=small; i++) down[k++]=i;

        for(i=0; i<k; i++) {
            for(l=0; l<j; l++) {
                if (up[l]%down[i]==0) { up[l]=up[l]/down[i]; down[i]=1; }
            }
        }

        num=1;
        for(l=0; l<j; l++) num=num*up[l];

        denom=1;
        for(i=0; i<k; i++) denom=denom*down[i];

        printf("%lld things taken %lld at a time is %lld exactly.\n", n, r, num/denom);
    }

    return 0;
}
