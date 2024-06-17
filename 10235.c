#include <stdio.h>
#include <math.h>
#include <string.h>

int if_prime(int num)
{
    int n;

    if (num==1) return 0;
    else if (num==0) return 0;

    for(n=2; n<=sqrt(num); n++) if (num%n==0) return 0;
    return 1;
}

int reverse_num(int a)
{
    int ara[16], ara2[16];
    int i=0, j, k=-1, p;
    double sum=0;

    for ( ; ; ) {
        ara[i]=a%10;
        a=a/10;
        if (a==0) break;
        i++;
    }
    for (j=i; j>=0; j--) { k++; ara2[k]=ara[j]; }
    for (k=0; k<=i; k++) sum=sum+ara2[k]*pow(10, k);
    return (int)sum;
}

int if_palin(int a)
{
    char str1[16], str2[16];
    int i=0, j=0;

    for ( ; ; ) {
        str1[i]=(a%10)+48;
        a=a/10;
        if (a==0) break;
        i++;
    }
    str1[i+1]='\0';
    for(i=(strlen(str1)-1); i>=0; i--) {
        str2[j]=str1[i];
        j++;
    }
    str2[j]='\0';
    for (i=0; i<strlen(str1); i++) if(str1[i]!=str2[i]) break;
    if (i==strlen(str1)) return 1;
    return 0;
}

int main ()
{
    int N;
    while(scanf("%d", &N)==1) {
        if (if_prime(N)==1 && (if_palin(N)==1)) printf("%d is prime.\n", N);
        else if (if_prime(N)==1 && if_prime(reverse_num(N))==1) printf("%d is emirp.\n", N);
        else if (if_prime(N)==1) printf("%d is prime.\n", N);
        else if (if_prime(N)==0) printf("%d is not prime.\n", N);
    }
    return 0;
}
