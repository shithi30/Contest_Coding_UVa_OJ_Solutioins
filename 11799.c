#include <stdio.h>
#include <malloc.h>

int main ()
{
    int test, t, i, *speeds, num, run;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {
        scanf("%d", &num);
        speeds=(int)malloc(num*sizeof(int));
        run=-1;

        for(i=0; i<num; i++) {
            scanf("%d", &speeds[i]);
            if (speeds[i]>run) run=speeds[i];
        }

        printf("Case %d: %d\n", t, run);
        free(speeds);
    }
    return 0;
}
