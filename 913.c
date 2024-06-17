#include <stdio.h>
#include <math.h>

long long int num_to_line(long long int num)
{
    return (num+1)/2;
}

int main ()
{
    long long int num, n, sum, line;

    while(scanf("%lld", &num)==1) {

        line=num_to_line(num);
        n=1+2*(line*line-1);
        sum=n+(n-2)+(n-4);

        printf("%lld\n", sum);
    }

    return 0;
}
