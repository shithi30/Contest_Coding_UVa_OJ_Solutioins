#include <stdio.h>
#include <string.h>

int main ()
{
    char strmain[1000], strtex[1000];
    int i, j, k, flag=0;

    while(gets(strmain)) {
        j=0;
        for(i=0; i<strlen(strmain); i++) {
            if ((strmain[i]=='\"')&&(flag==0)) {
                strtex[j]='`';
                strtex[j+1]='`';
                j=j+2;
                flag=1;
                continue;
            }
            else if ((strmain[i]=='\"')&&(flag==1)) {
                strtex[j]='\'';
                strtex[j+1]='\'';
                j=j+2;
                flag=0;
                continue;
            }
            strtex[j]=strmain[i];
            j=j+1;
        }
        strtex[j]='\0';
        puts(strtex);
    }
    return 0;
}
