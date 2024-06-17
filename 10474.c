#include <stdio.h>

int main ()
{
    int *ara, *ara2, i, j, k, q, random, n, test=0, temp;

    while(scanf("%d%d", &n, &q)==2) {
        if (n==0 && q==0) break;

        ara=(int)malloc(n*sizeof(int));
        ara2=(int)malloc(q*sizeof(int));

        for(i=0; i<n; i++) scanf("%d", &ara[i]);

        for(i=0; i<(n-1); i++) {
            for(j=i+1; j<n; j++) {
                if (ara[j]<ara[i]) {
                    temp=ara[i];
                    ara[i]=ara[j];
                    ara[j]=temp;
                }
            }
        }

        for(i=0; i<q; i++) scanf("%d", &ara2[i]);

        printf("CASE# %d:\n", ++test);

        for(i=0; i<q; i++) {
            for(j=0; j<n; j++) {
                if (ara2[i]==ara[j]) break;
            }
            if (j==n) printf("%d not found\n",ara2[i]);
            else printf("%d found at %d\n", ara2[i], j+1);
        }
    }
    return 0;
}
