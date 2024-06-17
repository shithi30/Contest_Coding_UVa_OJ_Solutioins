#include <stdio.h>
#include <malloc.h>
int main ()
{
    int num, test, m, i, k, count;
    int *ara;
    double sum, avg;
    scanf("%d", &test);
    for(i=0; i<test; i++) {
        scanf("%d", &num);
        ara=(int *)malloc(num*sizeof(int));
        count=0;
        sum=0;
        avg=0;
        for(k=0; k<num; k++) {
            scanf("%d", &ara[k]);
            sum=sum+ara[k];
        }
        avg=sum/num;
        for(m=0; m<num; m++) if (ara[m]>avg) count++ ;
        free(ara);
        printf("%0.3lf%%\n", ((double)count/num)*100);
    }
    return 0;
}

