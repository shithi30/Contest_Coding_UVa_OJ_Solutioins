#include <stdio.h>
int main ()
{
    int test, t, m, n, res;
    scanf("%d", &test);

    for(t=1; t<=test; t++) {

        scanf("%d%d", &n, &m);
        res=1; n=n-2; m=m-2;

        for ( ; ; ) {
            if (n%3==0) { res=res*(n/3); break; }
            n=n+1;
        }
        for ( ; ; ) {
            if (m%3==0) { res=res*(m/3); break; }
            m=m+1;
        }

        printf("%d\n", res);
    }
    return 0;
}
