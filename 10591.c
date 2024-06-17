#include <stdio.h>

int digit_sqr_sum(int n)
{
    int sum=0;
    for ( ; ; ) {
        sum=sum+(n%10)*(n%10);
        n=n/10;
        if (n==0) break;
    }
    return sum;
}

int main ()
{
    int num, test, i, num2, num3;
    scanf("%d", &test);
    for(i=1; i<=test; i++) {
        scanf("%d", &num);
        num3=num;
        for ( ; ; ) {
            num2=digit_sqr_sum(num);
            if (num2<10) break;
            else num=num2;
        }
        if (num2==1) printf("Case #%d: %d is a Happy number.\n", i, num3);
        else printf("Case #%d: %d is an Unhappy number.\n", i, num3);
    }
    return 0;
}
