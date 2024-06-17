#include <stdio.h>

int if_parity(int ara[100][100], int d, int *x, int *y)
{
    int i, j, sum_row, sum_col;

    for (i=0; i<d; i++) {
        sum_row=0;
        for (j=0; j<d; j++) sum_row+=ara[i][j];
        if (sum_row%2!=0) { *x=i; break; }
    }

    for(j=0; j<d; j++) {
        sum_col=0;
        for(i=0; i<d; i++) sum_col+=ara[i][j];
        if (sum_col%2!=0) { *y=j; return 0; }
    }

    if(*x==-1 && *y==-1) return 1;
    return 0;
}

int main ()
{
    int mat[100][100], i, j, dim, ch_x, ch_y, a, b;

    while(scanf("%d", &dim)==1) {
        if (dim==0) break;

        ch_x=ch_y=-1;

        for(i=0; i<dim; i++) for(j=0; j<dim; j++) scanf("%d", &mat[i][j]);

        if (if_parity(mat, dim, &ch_x, &ch_y)==1) { printf("OK\n"); continue; }
        else if (ch_x==-1 || ch_y==-1) { printf("Corrupt\n"); continue; }

        mat[ch_x][ch_y]=(mat[ch_x][ch_y]==0)? 1 : 0 ;

        a=ch_x; b=ch_y;
        ch_x=ch_y=-1;

        if (if_parity(mat, dim, &ch_x, &ch_y)==1) printf("Change bit (%d,%d)\n", a+1, b+1);
        else printf("Corrupt\n");
    }

    return 0;
}
