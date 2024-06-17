#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[100000000], str2[100000000], str3[100000000];
    int count, p, i, j;

    while (scanf("%s", str1)==1) {
        scanf("%s", str2);

        p=0; count=0;

        for(i=0; i<strlen(str1); i++) {
            for (j=p; j<strlen(str2); j++) {
                if (str1[i]==str2[j]) { str3[count++]=str1[i]; p=j+1; break; }
            }
        }
        str3[count]='\0';

        if (strlen(str1)==strlen(str3)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
