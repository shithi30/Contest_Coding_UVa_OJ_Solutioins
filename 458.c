#include <stdio.h>
#include <string.h>

int main ()
{
    char str[500];
    int i;

    while (gets(str)) {
        for(i=0; i<strlen(str); i++) str[i]=str[i]-7;
        puts(str);
    }
    return 0;
}
