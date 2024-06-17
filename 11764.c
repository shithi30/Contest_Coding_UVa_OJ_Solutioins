#include <stdio.h>
#include <malloc.h>

int main ()
{
    int test, t, i, walls, highs, lows;
    int *heights;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {
        scanf("%d", &walls);
        heights=(int)malloc(walls*sizeof(int));
        highs=0; lows=0;
        for(i=0; i<walls; i++) scanf("%d", &heights[i]);
        for(i=0; i<(walls-1); i++) {
            if (heights[i+1]>heights[i]) highs++;
            else if (heights[i+1]<heights[i]) lows++;
        }
        printf("Case %d: %d %d\n", t, highs, lows);
    }
    return 0;
}
