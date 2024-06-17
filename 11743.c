#include <stdio.h>
#include <string.h>

int digit_sum(int a)
{
    int sum=0;
    for (; ; ) {
        sum=sum+(a%10);
        a=a/10;
        if (a==0) break;
    }
    return sum;
}

int main ()
{
    char card[20];
    char buffer;

    int test, t, i, arad[8], sum1, sum2;

    scanf("%d", &test);
    buffer=getchar();

    for(t=1; t<=test; t++) {
        gets(card);

        sum1=0; sum2=0;

        arad[0]=(card[0]-48)*2; arad[1]=(card[2]-48)*2; arad[2]=(card[5]-48)*2; arad[3]=(card[7]-48)*2;
        arad[4]=(card[10]-48)*2; arad[5]=(card[12]-48)*2; arad[6]=(card[15]-48)*2; arad[7]=(card[17]-48)*2;

        for(i=0; i<8; i++) arad[i]=digit_sum(arad[i]);

        for(i=0; i<8; i++) sum1=sum1+arad[i];

        sum2=(card[1]-48)+(card[3]-48)+(card[6]-48)+(card[8]-48)+(card[11]-48)+(card[13]-48)+(card[16]-48)+(card[18]-48);

        if (((sum1+sum2)%10)==0) printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
