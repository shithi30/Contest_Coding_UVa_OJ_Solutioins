#include <stdio.h>
int main ()
{
    int alice, beto, clara;
    while(scanf("%d%d%d", &alice, &beto, &clara)==3) {
        if ((alice==1 && beto==0 && clara==0) || (alice==0 && beto==1 && clara==1)) printf("A\n");
        else if ((alice==1 && beto==0 && clara==1) || (alice==0 && beto==1 && clara==0)) printf("B\n");
        else if ((alice==1 && beto==1 && clara==0) || (alice==0 && beto==0 && clara==1)) printf("C\n");
        else printf("*\n");
    }
    return 0;
}
