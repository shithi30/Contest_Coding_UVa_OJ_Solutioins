#include <stdio.h>
#include <math.h>

int main ()
{
    long int num;

    while(scanf("%ld", &num)==1) {
        if (num==0) break;

        if(sqrt(num)==(int)sqrt(num)) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
