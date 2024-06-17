#include <stdio.h>
#include <string.h>
#include <math.h>

int hex_to_dec(char str[80])
{
    int i, j=0, num, sum=0;

    for (i=strlen(str)-1; i>=0; i--) {

        switch(str[i]) {
            case 'A' : num=10; break;
            case 'B' : num=11; break;
            case 'C' : num=12; break;
            case 'D' : num=13; break;
            case 'E' : num=14; break;
            case 'F' : num=15; break;

            default : num=str[i]-48;
        }

        sum=sum+num*pow(16, j++);
    }

    return sum;
}

void dec_to_bin(int n, char str[80])
{
    char ara2[80], ara[80];
    int i=0, j=0, zeros;

    for ( ; ; ) {
        ara[i++]=(n%2)+48;
        n=n/2;
        if (n==0) break;
    }
    ara[i]='\0';

    for (i=strlen(ara)-1; i>=0; i--) ara2[j++]=ara[i];
    ara2[j]='\0';

    zeros=13-strlen(ara2);

    for (i=0; i<zeros; i++) ara[i]='0';

    for (j=0; j<strlen(ara2); j++) ara[i++]=ara2[j];
    ara[i]='\0';

    strcpy(str, ara);
}

int main ()
{
    int n1, n2, res, test, i, t;
    char num1[80], num2[80], sign;

    scanf("%d", &test);
    getchar();

    for(t=1; t<=test; t++) {

        scanf("%s", num1);
        n1=hex_to_dec(num1);

        getchar();
        sign=getchar();
        getchar();

        scanf("%s", num2);
        n2=hex_to_dec(num2);

        res=(sign=='+')? n1+n2 : n1-n2;

        dec_to_bin(n1, num1);
        dec_to_bin(n2, num2);

        if (sign=='+') printf("%s + %s = %d\n", num1, num2, res);
        else printf("%s - %s = %d\n", num1, num2, res);
    }

    return 0;
}
