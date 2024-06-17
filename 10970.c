#include <stdio.h>

int main ()
{
    int a, b;

    while(scanf("%d%d", &a, &b)==2) {
        printf("%d\n", (a-1)+a*(b-1));
    }
    return 0;
}
