#include <stdio.h>

int main ()
{
    long long int c1, c2, a, b;
    int test, t;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {
        scanf("%lld%lld", &c1, &c2);

        if (!((c1+c2)%2==0 && (c1-c2)%2==0)) { printf("impossible\n"); continue; }

        a=(c1+c2)/2;
        b=(c1-c2)/2;

        if (a<0 || b<0) { printf("impossible\n"); continue; }
        (a>=b)? printf("%lld %lld\n", a, b) : printf("%lld %lld\n", b, a);
    }
    return 0;
}
