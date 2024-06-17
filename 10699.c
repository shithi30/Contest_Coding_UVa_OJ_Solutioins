#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
    int i;

    for(i=2; i<=sqrt(num); i++) if (num%i==0) return 0;
    return 1;
}

int main ()
{
    int num, i, j, count;
    int ara[1000];

    while (scanf("%d", &num)==1) {
        if (num==0) break;

        j=0; count=0;

        for(i=2; i<=sqrt(num); i++) {
            if (num%i==0) {
                ara[j++]=i;
                if ((i*i)!=num) ara[j++]=num/i;
            }
        }
        ara[j]=num;

        for(i=0; i<=j; i++) if (is_prime(ara[i])==1) count++;

        printf("%d : %d\n", num, count);
    }

    return 0;
}
