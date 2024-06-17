#include <stdio.h>
int main ()
{
    int a, b, c, L, i;
    long int d, count;

    for ( ; ; ) {
        scanf("%d%d%d%ld%d", &a, &b, &c, &d, &L);
        if (a==0 && b==0 && c==0 && d==0 && L==0) break;
        count=0;
        for (i=0; i<=L; i++) {
            if (((a*i*i+b*i+c)%d)==0) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
