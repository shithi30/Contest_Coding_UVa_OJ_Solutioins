#include <stdio.h>
#include <string.h>

int i=1;

void get_string(char str[50000])
{
    char str2[50000];
    int j;

    for(j=0; j<i; j++) str2[j]='1';
    str2[j]='\0';

    strcpy(str, str2);
    i++;
}

int main ()
{
    int ones_of, j, num, n, len;
    char str[50000];

    while(scanf("%d", &ones_of)==1) {

        if (ones_of==0) { printf("0\n"); continue; }

        for( ; ; ) {

            get_string(str);

            len=strlen(str);
            num=0;

            for(j=0; j<len; j++) {
                num=num*10+(str[j]-48);
                num=num%ones_of;
            }

            if (num==0) { printf("%d\n", strlen(str)); i=1; break; }
        }
    }

    return 0;
}
