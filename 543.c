#include <stdio.h>
#include <math.h>

int if_prime(int n)
{
    int i;

    for (i=2; i<=sqrt(n); i++) if ((n%i)==0) return 0;
    return 1;
}

int main ()
{
    int n, i;

    while (scanf("%d", &n)==1) {
        if (n==0) break;

        for(i=n-2;  ; i--) if (if_prime(i)==1 && if_prime(n-i)==1) break;

        printf("%d = %d + %d\n", n, n-i, i);
    }

    return 0;
}
