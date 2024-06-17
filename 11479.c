#include <stdio.h>
int main ()
{
    long int a, b, c;
    int i, test;
    scanf("%d", &test);
    for (i=0; i<test; i++) {
        scanf("%ld%ld%ld", &a, &b, &c);
        if ((a+b)>c && (b+c)>a && (c+a)>b) {
            if (a!=b && b!=c && c!=a) printf("Case %d: Scalene\n", i+1);
            else if (a==b && b==c) printf("Case %d: Equilateral\n", i+1);
            else if (a==b || b==c || c==a) printf("Case %d: Isosceles\n", i+1);
        }
        else printf("Case %d: Invalid\n", i+1);
    }
    return 0;
}
