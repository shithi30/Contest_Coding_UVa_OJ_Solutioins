#include <stdio.h>
#include <math.h>

int main ()
{
    int primes1[1000], *primes2, p, n, c, i, j, count;

    while(scanf("%d%d", &n, &c)==2) {
        p=-1;
        for(i=1; i<=n; i++) {
            for(j=2; j<=sqrt(i); j++) if (i%j==0) break;
            if (j>sqrt(i)) primes1[++p]=i;
        }

        printf("%d %d:", n, c);
        if (p%2!=0) {
            if ((c*2)>(p+1)) { for(i=0; i<=p; i++) printf(" %d", primes1[i]); printf("\n\n"); continue; }
            count=0;
            for(i=(p/2)-c+1;  ; i++) { printf(" %d", primes1[i]); count++; if (count==2*c) break; }
            printf("\n\n");
        }
        else {
            if ((c*2-1)>(p+1)) { for(i=0; i<=p; i++) printf(" %d", primes1[i]);  printf("\n\n"); continue; }
            count=0;
            for(i=(p/2)-c+1;  ; i++) { printf(" %d", primes1[i]); count++; if (count==(2*c)-1) break; }
            printf("\n\n");
        }
    }
    return 0;
}
