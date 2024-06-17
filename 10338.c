#include <stdio.h>
#include <string.h>

long long fact(long long int num)
{
    long long int f=1, n;

    for(n=num; n>=2; n--) f=f*n;

    return f;
}

int main ()
{
    char str[50];
    long long int test, t, i, len, j, differents[25], ind, freqs[25], p;

    scanf("%lld", &test); getchar();

    for(t=1; t<=test; t++) {

        gets(str);

        len=strlen(str); ind=0; for(i=0; i<25; i++) freqs[i]=0;

        for(i=0; i<len; i++) {
            for(j=0; j<i; j++) if (str[i]==str[j]) break;
            if (j==i) differents[ind++]=str[i];
        }

        for(i=0; i<ind; i++) {
            for(j=0; j<len; j++) {
                if (differents[i]==str[j]) freqs[i]++;
            }
        }

        p=fact(len);

        for(i=0; i<ind; i++) {
            if (freqs[i]!=1) p=p/fact(freqs[i]);
        }

        printf("Data set %lld: %lld\n", t, p);
    }

    return 0;
}

