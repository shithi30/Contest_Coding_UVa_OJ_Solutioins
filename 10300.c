#include <stdio.h>
int main ()
{
    int test, farmers, size, number, factor;
    int t, i, sum;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {
        sum=0;
        scanf("%d", &farmers);
        for(i=1; i<=farmers; i++) {
            scanf("%d%d%d", &size, &number, &factor);
            sum=sum+(size*factor);
        }
        printf("%d\n", sum);
    }
    return 0;
}
