#include <stdio.h>
#include <string.h>

int m, n;

int if_valid(int x, int y)
{
    if ((x>=0 && x<m) && (y>=0 && y<n)) return 1;
    return 0;
}

int main ()
{
    char way[10][10], path[10];
    int tests, t, i, j, start_x, start_y, len, x, y;

    strcpy(path, "IEHOVA#");

    scanf("%d", &tests); getchar();

    for(t=0; t<tests; t++) {

        scanf("%d%d", &m, &n); getchar();
        for(i=0; i<m; i++) gets(way[i]);

        for(i=0; i<m; i++) {
            len=strlen(way[i]);
            for(j=0; j<len; j++) {
               if (way[i][j]=='@') { start_x=i; start_y=j; }
            }
        }

        len=strlen(path);

        for(i=0; i<len; i++) {

            x=start_x; y=start_y-1;
            if(if_valid(x, y) && way[x][y]==path[i]) { if(i!=6) printf("left "); else printf("left"); start_x=x; start_y=y; continue; }

            x=start_x; y=start_y+1;
            if(if_valid(x, y) && way[x][y]==path[i]) { if(i!=6) printf("right "); else printf("right"); start_x=x; start_y=y; continue; }

            y=start_y; x=start_x-1;
            if(if_valid(x, y) && way[x][y]==path[i]) { if(i!=6) printf("forth "); else printf("forth"); start_x=x; start_y=y; continue; }
        }

        printf("\n");
    }

    return 0;
}
