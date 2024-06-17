#include <stdio.h>
#include <string.h>
int main ()
{
    int test, t, i, j, k;
    char name1[25], name2[25];
    char buffer;

    scanf("%d", &test);
    buffer=getchar();

    for (t=1; t<=test; t++) {

        gets(name1);
        gets(name2);

        if (strlen(name1)!=strlen(name2)) { printf("No\n"); continue; }

        for (i=0; i<strlen(name1); i++) {
            if (name1[i]!=name2[i]) break;
        }
        if (i==strlen(name2)) { printf("Yes\n"); continue; }

        for(i=0; i<strlen(name1); i++) {
            if (name1[i]!=name2[i]) {
                if ((name1[i]=='a'||name1[i]=='e'||name1[i]=='i'||name1[i]=='o'||name1[i]=='u')&&(name2[i]=='a'||name2[i]=='e'||name2[i]=='i'||name2[i]=='o'||name2[i]=='u')) continue;
                break;
            }
        }
        if (i==strlen(name1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
