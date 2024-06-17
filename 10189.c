#include <stdio.h>

int row, col;

int is_valid_row(int r)
{
    if (r>=0 && r<row) return 1;
    return 0;
}

int is_valid_col(int c)
{
    if (c>=0 && c<col) return 1;
    return 0;
}

int main ()
{
    char mines[150][150];
    int m, n, i, j, count, test=0;

    while(scanf("%d%d", &m, &n)==2) {
        getchar();

        if (m==0 && n==0) break;

        row=m; col=n;

        for(i=0; i<m; i++) gets(mines[i]);

        if (test!=0) printf("\n");
        printf("Field #%d:\n", ++test);

        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                if (mines[i][j]=='*') { printf("*");  continue; }

                count=0;

                if (is_valid_col(j-1) && mines[i][j-1]=='*') count++;
                if (is_valid_col(j+1) && mines[i][j+1]=='*') count++;
                if (is_valid_row(i-1)) {
                    if (is_valid_col(j-1) && mines[i-1][j-1]=='*') count++;
                    if (mines[i-1][j]=='*') count++;
                    if (is_valid_col(j+1) && mines[i-1][j+1]=='*') count++;
                }
                if (is_valid_row(i+1)) {
                    if (is_valid_col(j-1) && mines[i+1][j-1]=='*') count++;
                    if (mines[i+1][j]=='*') count++;
                    if (is_valid_col(j+1) && mines[i+1][j+1]=='*') count++;
                }
                printf("%d", count);
            }
            printf("\n");
        }
    }

    return 0;
}

