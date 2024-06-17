#include <stdio.h>
#include <ctype.h>
#include <string.h>

void low(char ara[])
{
    int i;
    for(i=0; i<strlen(ara); i++) ara[i]=tolower(ara[i]);
}

int sum_digits(int a)
{
    int sum=0;
    for ( ; ; ) {
        sum=sum+(a%10);
        a=a/10;
        if (a==0) break;
    }
    return sum;
}

int main ()
{
    char name1[50], name2[50];
    int i, j, k, sum1, sum2, num1, num2, a, b;
    double percent;

    while (gets(name1)) {
        gets(name2);
        low(name1); low(name2);

        sum1=0;
        for (i=0; i<strlen(name1); i++) {
            if (name1[i]>='a' && name1[i]<='z') sum1=sum1+(name1[i]-96);
        }
        a=sum1;
        for ( ; ; ) {
            num1=sum_digits(a);
            a=num1;
            if (num1<10) break;
        }

        sum2=0;
        for (i=0; i<strlen(name2); i++) {
            if (name2[i]>='a' && name2[i]<='z') sum2=sum2+(name2[i]-96);
        }
        b=sum2;
        for ( ; ; ) {
            num2=sum_digits(b);
            b=num2;
            if (num2<10) break;
        }

        if (num1==0 && num2==0) { printf("\n"); continue; }

        if (num1>=num2) percent=((double)num2/num1)*100;
        else if (num2>=num1) percent=((double)num1/num2)*100;

        printf("%0.2lf %%\n", percent);
    }
    return 0;
}
