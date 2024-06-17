#include <stdio.h>
int main ()
{
    int chilo, pelo, cost, test, i, res, div, rem, temp;
    scanf("%d", &test);
    for (i=0; i<test; i++) {
        scanf("%d%d%d", &chilo, &pelo, &cost);
        getchar();
        div=(chilo+pelo)/cost;
        rem=(chilo+pelo)%cost;
        res=div;
        while((div+rem)>=cost) {
            temp=div+rem;
            div=temp/cost;
            rem=temp%cost;
            res +=div;
        }
        printf("%d\n", res);
    }
    return 0;
}
