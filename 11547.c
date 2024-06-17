#include <stdio.h>
#include <math.h>
int main ()
{
    int test, i, rem;
    long long int n, res;
    scanf("%d", &test);
    for (i=1; i<=test; i++) {
        scanf("%lld", &n);
        res=((((n*567)/9)+7492)*235)/47-498;
        rem=res%100;
        printf("%d\n", abs(rem/10));
    }
    return 0;
}
