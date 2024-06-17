#include <stdio.h>
#include <string.h>

int main ()
{
    char str[50];
    int i, test=0;

    while(gets(str)) {
        if (str[0]=='*') break;
        printf("Case %d: ", ++test);
        if (str[0]=='H') printf("Hajj-e-Akbar\n");
        else printf("Hajj-e-Asghar\n");
    }
    return 0;
}
