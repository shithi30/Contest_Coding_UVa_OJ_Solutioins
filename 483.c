#include <stdio.h>
#include <string.h>

int main ()
{
    char sen[1000];
    char strs[500][100];
    int i, j, k, spaces;

    while(gets(sen)) {
        spaces=0; j=0;
        for(i=strlen(sen)-1; i>=0; i--) {
            if (sen[i]==' ') { strs[spaces][j]='\0'; spaces=spaces+1; j=0; continue; }
            strs[spaces][j]=sen[i];
            if (i==0) strs[spaces][j+1]='\0';
            j=j+1;
        }
        for(k=spaces; k>=0; k--) {
            if (k==0) { printf("%s", strs[k]); continue; }
            printf("%s ", strs[k]);
        }
        printf("\n");
    }

    return 0;
}
