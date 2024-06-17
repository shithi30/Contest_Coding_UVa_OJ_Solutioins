#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main ()
{
    int n, test, risk, capacity, *w, i, k, m, sum;
    scanf("%d", &test);
    for (i=1; i<=test; i++) {

        fflush(stdin);

        scanf("%d%d%d", &n, &risk, &capacity);
        w=(int *)malloc(n*sizeof(int));
        for (k=0; k<n; k++) {scanf("%d", &w[k]);}

        for ( ; ; ) {
           sum=0;
           if (risk>n) risk=n;
           for (m=0; m<risk; m++) sum=sum+w[m];
           if (sum<=capacity) { printf("Case %d: %d\n", i, risk); break; }
           else {
                risk=risk-1;
                if (risk==0) { printf("Case %d: %d\n", i, risk); break; }
           }
        }
        free(w);
    }
    return 0;
}
