#include <stdio.h>

int main ()
{
    long int sum, num1, num2, count, rem1, rem2, rems;

    while(scanf("%ld%ld", &num1, &num2)==2) {
        if (num1==0 && num2==0) break;
        sum=num1+num2;
        count=0;

        for( ; ; ) {
            rem1=num1%10;
            rem2=num2%10;
            rems=sum%10;

            if (rems!=(rem1+rem2) && rems!=(rem1+rem2+1)) count++;

            num1=num1/10;
            num2=num2/10;
            sum=sum/10;

            if (num1==0 && num2==0 && sum==0) break;
        }

        if (count==0) printf("No carry operation.\n");
        else if (count==1) printf("1 carry operation.\n");
        else if (count>1) printf("%ld carry operations.\n", count);
    }
    return 0;
}
