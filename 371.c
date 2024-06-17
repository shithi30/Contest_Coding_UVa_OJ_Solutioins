#include <stdio.h>
#include <malloc.h>

long long int ackerman(long long int num)
{
    long long int count=0;
    for ( ; ; ) {
        if (num%2==0) num=num/2;
        else num=(3*num)+1;
        count++;
        if (num==1) break;
    }
    return count;
}

int main ()
{
    long long int low, up, max, *ara, j, i, temp;

    while(scanf("%lld%lld", &low, &up)==2) {
        if (up==0 && low==0) break;
        if (low>up) { temp=low; low=up; up=temp; }

        ara=(long long int)malloc((up-low+1)*sizeof(long long int));

        for(i=low, j=0; i<=up; i++) ara[j++]=ackerman(i);
        max=0;
        for(i=0; i<j; i++) if (ara[i]>max) max=ara[i];

        for(i=0; i<j; i++) if (max==ara[i]) { printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", low, up, i+low, ara[i]); break; }

        free(ara);
    }
    return 0;
}
