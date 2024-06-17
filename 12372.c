#include <stdio.h>

int main ()
{

    int t, test, i, dim, apt;

    scanf("%d", &test);

    for (t=1; t<=test; t++) {
        apt=1;

        for (i=0; i<3; i++) {
            scanf("%d", &dim);
            if (dim>20) apt=0;
        }

        if (apt==1) printf("Case %d: good\n", t);
        else printf("Case %d: bad\n", t);
    }

    return 0;
}
