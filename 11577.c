#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

int main ()
{
    int i, *ara, max, test, t;
    char str[500];

    scanf("%d", &test);
    getchar();

    for(t=1; t<=test; t++) {

        gets(str);

        ara=(int)calloc(26, sizeof(int));
        max=0;

        for(i=0; i<strlen(str); i++) {
            str[i]=tolower(str[i]);
            if (str[i]>='a' && str[i]<='z') ara[str[i]-97]++;
        }
        for(i=0; i<=25; i++) {
            if (ara[i]>max) max=ara[i];
        }
        for(i=0; i<=25; i++) {
            if (ara[i]==max) printf("%c", i+97);
        }

        printf("\n");

        free(ara);
    }
    return 0;
}
