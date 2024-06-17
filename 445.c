#include <stdio.h>
#include <string.h>

int main ()
{
    int i, p, j;
    char str[150];

    while(gets(str)) {
        for (i=0; i<strlen(str); i++) {

            if (str[i]=='!') { printf("\n"); continue; }

            p=str[i]-48;

            for ( ; ; ) {
                i++;
                if (str[i]>='0' && str[i]<='9') p=p+(str[i]-48);
                else break;
            }

            if (str[i]=='b') { for (j=1; j<=p; j++) printf(" "); continue; }
            for (j=1; j<=p; j++) printf("%c", str[i]);
        }

        printf("\n");
    }

    return 0;
}

