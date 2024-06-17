#include <stdio.h>

int main ()
{
    long long int num, sum, i;

    while(scanf("%lld", &num)==1) {
        sum=0;
        for (i=1; i<=num; i++) sum+=(i*i*i);
        printf("%lld\n", sum);
    }
    return 0;
}
