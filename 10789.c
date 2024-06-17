#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

int is_prime(int num)
{
    int i;

    if (num==1 || num==0) return 0;
    for(i=2; i<=sqrt(num); i++) if (num%i==0) return 0;
    return 1;
}

int main ()
{
    int test, t, *capital_freq, *small_freq, *num_freq, i, flag;
    char str[2500];

    scanf("%d", &test); getchar();

    for(t=1; t<=test; t++) {
        gets(str);

        flag=1;

        capital_freq=(int)calloc(26, sizeof(int));
        small_freq=(int)calloc(26, sizeof(int));
        num_freq=(int)calloc(10, sizeof(int));

        for(i=0; i<strlen(str); i++) {
            if (str[i]>='0' && str[i]<='9') num_freq[str[i]-48]++;
            else if (str[i]>='A' && str[i]<='Z') capital_freq[str[i]-65]++;
            else if (str[i]>='a' && str[i]<='z') small_freq[str[i]-97]++;
        }

        printf("Case %d: ", t);
        for(i=0; i<10; i++) if (is_prime(num_freq[i])) { printf("%c", 48+i); flag=0; }
        for(i=0; i<26; i++) if (is_prime(capital_freq[i])) { printf("%c", 65+i); flag=0; }
        for(i=0; i<26; i++) if (is_prime(small_freq[i])) { printf("%c", 97+i); flag=0; }
        if (flag==1) printf("empty");
        printf("\n");
    }

    return 0;
}
