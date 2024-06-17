#include <stdio.h>
int main ()
{
    int test, n, i, count, k, age, res;
    scanf("%d", &test);
    for (i=0; i<test; i++) {
        scanf("%d", &n);
        for (k=1; k<=n; k++) {
            scanf("%d", &age);
            if (k==(((n-1)/2)+1)) res=age;
        }
        printf("Case %d: %d\n",i+1, res);
    }
    return 0;
}
