#include <stdio.h>

int main ()
{
    int n, i, j, flag;

    while(scanf("%d", &n)==1) {
        if (n==0) break;

        flag=0;
        for(i=1; i<=100; i++) {
            for (j=1; j<i; j++) {
                if ((i*i*i-j*j*j)==n) { printf("%d %d\n", i, j); flag=1; break; }
            }
            if (flag==1) break;
        }
        if (flag==0) printf("No solution\n");
    }

    return 0;
}
