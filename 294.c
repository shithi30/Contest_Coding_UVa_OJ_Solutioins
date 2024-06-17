#include <stdio.h>
#include <math.h>
#include <malloc.h>

int num_of_factors(int num)
{
    int i, count=0;

    for(i=1; i<=sqrt(num); i++) {
        if (num%i==0) {
            count++;
            if (i*i!=num) count++;
        }
    }

    return count;
}

int main ()
{
    int test, n1, n2, ind, h, i, t, *factor_count;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {

        scanf("%d%d", &n1, &n2);

        factor_count=(int)malloc(((n2-n1)+1)*sizeof(int));

        ind=0; h=-1;

        for(i=n1; i<=n2; i++) {
            factor_count[ind]=num_of_factors(i);
            if (factor_count[ind]>h) h=factor_count[ind];
            ind++;
        }

        for(i=0; i<ind; i++) if (factor_count[i]==h) { printf("Between %d and %d, %d has a maximum of %d divisors.\n", n1, n2, n1+i, num_of_factors(n1+i)); break; }
    }

    return 0;
}
