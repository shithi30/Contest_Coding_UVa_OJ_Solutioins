#include <stdio.h>
#include <string.h>

void dec_to_ternary(long int num, char str[80])
{
    int i=0, j=0;
    char str2[80];

    for ( ; ; ) {
       str[i++]=(num%3)+48;
       num=num/3;
       if (num==0) break;
    }
    str[i]='\0';

    for(i=strlen(str)-1; i>=0; i--) str2[j++]=str[i];
    str2[j]='\0';

    strcpy(str, str2);
}

int main ()
{
    char ara[80];
    long int n;

    for( ; ; ) {
        scanf("%ld", &n);
        if (n<0) break;
        dec_to_ternary(n, ara);
        puts(ara);
    }

    return 0;
}
