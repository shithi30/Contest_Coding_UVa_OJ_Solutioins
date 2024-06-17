#include <stdio.h>

int main ()
{
    int num, i;
    long long int sum;

    while(scanf("%d", &num)==1) {
        if (num==0) break;
        sum=0;
        for (i=num; i>=1; i--) sum+=(i*i);
        printf("%lld\n", sum);
    }
    return 0;
}
