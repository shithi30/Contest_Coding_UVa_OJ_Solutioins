#include <stdio.h>
#include <math.h>
#include <string.h>

void to_bin(int num, char bin[100])
{
    int rem, i=0, j=0;
    char str[100], str2[100];

    for ( ; ; ) {
        rem=num%2;
        str[i++]=rem+48;
        num=num/2;
        if (num==0) break;
    }
    str[i]='\0';

    for (i=strlen(str)-1; i>=0; i--) str2[j++]=str[i]; str2[j]='\0';

    strcpy(bin, str2);
}

int hex_to_deci(int num)
{
    int i=0, rem, sum=0;

    for ( ; ; ) {
        rem=num%10;
        sum=sum+rem*pow(16, i++);
        num=num/10;
        if (num==0) break;
    }

    return sum;
}

int main ()
{
    int test, num, i, j, h1, h2;
    char bin[90];

    scanf("%d", &test);

    for(i=0; i<test; i++) {
        scanf("%d", &num);

        h1=h2=0;

        to_bin(num, bin);

        for(j=0; j<strlen(bin); j++) if (bin[j]=='1') h1++;

        to_bin(hex_to_deci(num), bin);

        for(j=0; j<strlen(bin); j++) if (bin[j]=='1') h2++;

        printf("%d %d\n", h1, h2);
    }

    return 0;
}

