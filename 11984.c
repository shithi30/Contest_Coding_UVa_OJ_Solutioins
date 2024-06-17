#include <stdio.h>
int main ()
{
    int test, cel, fer, i;
    double res;
    scanf("%d", &test);
    for (i=0; i<test; i++) {
        scanf("%d%d", &cel, &fer);
        res=cel+fer*(5.0/9);
        printf("Case %d: %0.2lf\n", i+1, res);
    }
    return 0;
}
