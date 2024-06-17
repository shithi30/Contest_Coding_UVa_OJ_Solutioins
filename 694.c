#include <stdio.h>

int main ()
{
    long long int a, l, count, b;
    int test=0;

    while(scanf("%lld%lld", &a, &l)==2) {

        if (a<0 && l<0) break;
        count=0; b=a;

        for ( ; ; ) {
            if (a==1) { count++; break; }
            else if (a%2==0) { a=a/2; count++; }
            else { a=3*a+1; count++; if (a>l) break; }
        }

        printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n", ++test, b, l, count);
    }

    return 0;
}
