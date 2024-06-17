#include <stdio.h>

int GCD(int a, int b)
{
    int k;
    for(k=a; k>=1; k--) if (((a%k)==0) && ((b%k)==0)) return k;
    return 1;
}

int main ()
{
    int N, i, j;
    long int G;

    while(scanf("%d", &N)) {
        if(N==0) break;
        G=0;
        for (i=1; i<N; i++) {
            for(j=i+1; j<=N; j++) G=G+GCD(i, j);
        }
        printf("%ld\n", G);
    }
    return 0;
}
