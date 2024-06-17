#include <stdio.h>
#include <string.h>

int main ()
{
    char str[1000000];
    int num, i, len;

    while(gets(str)) {
        if (str[0]=='0') break;

        num=0; len=strlen(str);

        for(i=0; i<len; i++) {
            num=num*10+(str[i]-48);
            num=num%17;
        }

        if (num==0) printf("1\n");
        else printf("0\n");
    }

    return 0;
}

