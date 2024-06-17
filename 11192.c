#include <stdio.h>
#include <string.h>
#include <math.h>

char str_rev(char ara[])
{
    int i;
    for(i=strlen(ara)-1; i>=0; i--) printf("%c", ara[i]);
}

int to_num(char ara[])
{
    int i, p=0;
    double sum=0;
    for(i=strlen(ara)-1; i>=0; i--) {
        sum=sum+((ara[i]-48)*pow(10, p));
        p++;
    }
    return (int)sum;
}

int main ()
{
    int grp, i, count, row, length;
    char numstr[16];
    char str[150];
    char revs[100][100];

    for( ; ; ) {
        scanf("%s", numstr);
        grp=to_num(numstr);

        if (grp==0) break;

        scanf("%s", str);

        length=strlen(str)/grp;

        count=0; row=0;
        for(i=0; i<strlen(str); i++) {
            revs[row][count]=str[i];
            count++;
            if (count==length) { revs[row][count]='\0'; count=0;  row=row+1; }
        }
        for(i=0; i<row; i++) str_rev(revs[i]);
        printf("\n");
    }
    return 0;
}
