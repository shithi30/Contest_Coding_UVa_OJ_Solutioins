#include <stdio.h>

int main ()
{
    int test, t, i, j, k, amplitude, frequency;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {

        scanf("%d", &amplitude);
        scanf("%d", &frequency);

        for(k=1; k<=frequency; k++) {
            for(i=1; i<=(amplitude-1); i++) {
                for(j=1; j<=i; j++) printf("%d", i);
                printf("\n");
            }

            for(i=1; i<=amplitude; i++) { printf("%d", amplitude); if(i==amplitude) printf("\n"); }

            for(i=(amplitude-1); i>=1; i--) {
                for(j=1; j<=i; j++)  printf("%d", i);
                printf("\n");
            }
            if((t==test) && (k==frequency)) continue;
            printf("\n");
        }
    }
    return 0;
}
