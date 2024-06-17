#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main ()
{
    int i, test, t, rate, *relevances;
    char pages[15][150];

    scanf("%d", &test);
    getchar();

    for (t=1; t<=test; t++) {
        rate=-1;
        relevances=(int)malloc(10*sizeof(int));

        for(i=0; i<10; i++) {
           scanf("%s", pages[i]);
           getchar();
           scanf("%d", &relevances[i]);
           if (relevances[i]>rate) rate=relevances[i];
        }

        printf("Case #%d:\n", t);
        for(i=0; i<10; i++) if (relevances[i]==rate) puts(pages[i]);
    }

    return 0;
}
