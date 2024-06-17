#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main ()
{
    int i, columns, sum, avg, moves, *ara, test=0;

    for ( ; ; ) {
        scanf("%d", &columns);
        if (columns==0) break;
        ara=(int)malloc(columns*sizeof(int));
        sum=0;

        for(i=0; i<columns; i++) {
            scanf("%d", &ara[i]);
            sum+=ara[i];
        }

        avg=sum/columns;
        moves=0;

        for(i=0; i<columns; i++) if (ara[i]!=avg) moves+=abs(ara[i]-avg);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++test, moves/2);
        free(ara);
    }
    return 0;
}
