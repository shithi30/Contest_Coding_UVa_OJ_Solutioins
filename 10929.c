#include <stdio.h>
#include <string.h>

void cut_pad(char ara[1500])
{
    int i, j=0;
    char ara2[1500];

    for(i=0; i<strlen(ara); i++) {
        if (ara[i]>='0' && ara[i]<='9') break;
    }

    for( ; i<strlen(ara); i++) {
        if (ara[i]>='0' && ara[i]<='9') ara2[j++]=ara[i];
    }
    ara2[j]='\0';

    strcpy(ara, ara2);
}

int main ()
{
    char str[1500];
    int num, i;

    for( ; ; ) {

        gets(str);
        cut_pad(str);
        if (strlen(str)==1 && str[0]=='0') break;

        num=str[0]-48;

        for(i=0; i<strlen(str)-1; i++) {
            num=num*10+(str[i+1]-48);
            num=num%11;
        }

        if (num==0) printf("%s is a multiple of 11.\n", str);
        else printf("%s is not a multiple of 11.\n", str);
    }

    return 0;
}
