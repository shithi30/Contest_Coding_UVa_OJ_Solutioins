#include <stdio.h>

int if_all_zero(int ara[110], int a)
{
    int i;

    for(i=0; i<a; i++) if (ara[i]!=0) return 0;
    return 1;
}

int main ()
{
    int p, elements, *ara, j, i, count;

    while(scanf("%d", &elements)==1) {
        if (elements==0) break;

        for (p=1;  ; p++) {
            count=i=0;

            ara=(int)malloc(elements*sizeof(int));
            for(j=0; j<elements; j++) ara[j]=1; ara[0]=0;

            for ( ; ; ) {

                while(i<elements) {
                    if (ara[i]==1) count++;
                    if (count==p) { ara[i]=0; break; }
                    i++;
                    if (i==elements) i=0;
                }

                count=0;
                if (if_all_zero(ara, elements)==1) break;
                else { i++; if (i==elements) i=0; }
            }

            if (i==12) break;
        }

        printf("%d\n", p);
    }

    return 0;
}
