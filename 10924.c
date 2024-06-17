#include <stdio.h>
#include <string.h>
#include <math.h>

int is_prime(int num);
int main ()
{
    char word[20];
    int i, sum;
    while (scanf("%s", word)!=EOF) {
        getchar();
        sum=0;
        for(i=0; i<strlen(word); i++) {
            if (word[i]>='a' && word[i]<='z') sum=sum+word[i]-96;
            else if (word[i]>='A' && word[i]<='Z') sum=sum+word[i]-38;
        }
        if (is_prime(sum)==1) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
int is_prime(int num)
{
    int n;
    for(n=2; n<=sqrt(num); n++) {
        if (num%n==0) return 0;
    }
    return 1;
}
