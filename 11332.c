#include <stdio.h>
int main ()
{
    long long int a;
    int sum, div, rem;
    for ( ; ; ) {
        scanf("%lld", &a);
        if (a==0) break;
        do {
            sum=0;
            for ( ; ; ) {
                sum=sum+(a%10);
                a=a/10;
                if (a==0) break;
            }
            if (sum<10) printf("%d\n", sum);
            else if (sum>9) a=sum;
        } while(sum>9);
    }
    return 0;
}
