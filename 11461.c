#include <stdio.h>
#include <math.h>
int main ()
{
    long int a, b, num, count;
    double root;
    for ( ; ; ) {
        scanf("%ld%ld", &a, &b);
        count=0;
        if (a==0 && b==0) break;
        for(num=a; num<=b; num++) {
            root=sqrt(num);
            if (root==(int)root) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
