#include <stdio.h>

int main ()
{
    long long int n, a, b, c, i;

    while(scanf("%lld", &n)==1) {
        if (n==0) break;

        a=0;
        b=1;

        for(i=1; i<=n; i++) {
            c=a+b;
            if (i==n) printf("%lld\n", c);
            a=b;
            b=c;
        }
    }
    return 0;
}
