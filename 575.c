#include <stdio.h>
#include <string.h>

int skew (char ara[])
{
    int i, sum=0, p=1;
    for(i=strlen(ara)-1; i>=0; i--) {
        sum=sum+(ara[i]-48)*(pow(2, p)-1);
        p++;
    }
    return sum;
}

int main ()
{
    char str[50];

    while(gets(str)) {
        if (str[0]=='0') break;
        printf("%d\n", skew(str));
    }
    return 0;
}
