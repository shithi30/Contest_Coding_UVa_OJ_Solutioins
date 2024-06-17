#include <stdio.h>
#include <string.h>

void cut_pad(char ara[100000])
{
    char ara2[100000];
    int i, len=strlen(ara), j=0;

    for(i=0; i<len; i++) if (ara[i]!='0') break;

    if (i==len) { strcpy(ara, "0"); return; }

    for(  ; i<len; i++) {
        ara2[j++]=ara[i];
    }
    ara2[j]='\0';

    strcpy(ara, ara2);
}

int main ()
{
    char str[100000], sign, str2[100000];
    long long int divisor, num, i, len, j;

    while(scanf("%s", str)==1) {

        for( ; ; ) {
            sign=getchar();
            if (sign=='/' || sign=='%') break;
        }
        scanf("%lld", &divisor);

        if (sign=='%') {
            num=0; len=strlen(str);

            for(i=0; i<len; i++) {
                num=num*10+(str[i]-48);
                num=num%divisor;
            }

            printf("%d\n", num);
        }

        else {
            num=0; len=strlen(str); j=0;

            for(i=0; i<len; i++) {
                num=num*10+(str[i]-48);
                str2[j++]=(num/divisor)+48;
                num=num%divisor;
            }
            str2[j]='\0';

            cut_pad(str2);

            puts(str2);
        }
    }

    return 0;
}
