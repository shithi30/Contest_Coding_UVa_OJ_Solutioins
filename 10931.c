#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main ()
{
    long long int num, sum;
    int *ara, ind, i, rem;
    while (scanf("%lld", &num)==1) {
        if (num==0) break;
        ind=0;
        sum=0;
        ara=(int*)malloc(0*sizeof(int));
        while(num!=0) {
            rem=num%2;
            ind++;
            ara=(int*)realloc(ara, ind*sizeof(int));
            ara[ind-1]=rem;
            num=num/2;
        }
        printf("The parity of ");
        for (i=ind-1; i>=0; i--) {
            printf("%d",ara[i]);
            sum=sum+ara[i];
        }
        free(ara);
        printf(" is %d (mod 2).\n", sum);
    }
    return 0;
}
