#include <stdio.h>
#include <malloc.h>

int main ()
{
    int test, i, types, max, sum, *plate, *limits, j;

    scanf("%d", &test);

    for (i=1; i<=test; i++) {

        scanf("%d%d", &types, &max);

        plate=(int) malloc(types*sizeof(int));
        limits=(int) malloc(types*sizeof(int));

        for (j=0; j<types; j++) scanf("%d", &plate[j]);
        for (j=0; j<types; j++) scanf("%d", &limits[j]);

        sum=0;

        for(j=0; j<types; j++) sum+=plate[j];

        if (sum>max) { printf("Case %d: No\n", i); continue; }

        for (j=0; j<types; j++) if (plate[j]>limits[j]) break;

        if (j==types) { printf("Case %d: Yes\n", i); continue; }
        printf("Case %d: No\n", i);
    }

    return 0;
}
