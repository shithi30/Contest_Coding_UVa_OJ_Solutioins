#include <stdio.h>

int main ()
{
    int q, div_x, div_y, i, x, y;

    while(scanf("%d", &q)==1) {
        if (q==0) break;

        scanf("%d%d", &div_x, &div_y);

        for(i=0; i<q; i++) {
            scanf("%d%d", &x, &y);

            x=x-div_x; y=y-div_y;

            if (x==0 || y==0) printf("divisa\n");
            else if (x>0 && y>0) printf("NE\n");
            else if (x<0 && y>0) printf("NO\n");
            else if (x<0 && y<0) printf("SO\n");
            else if (x>0 && y<0) printf("SE\n");
        }
    }

    return 0;
}
