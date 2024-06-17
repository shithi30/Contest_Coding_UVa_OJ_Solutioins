#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char str[250], alphabet[26], sames[26];
    int i, num, temp, t, k, frequency[26], ind=0, p, m, j, test, nums[26];

    for(i=0; i<26; i++) {
        frequency[i]=0;
        alphabet[i]=i+65;
    }

    scanf("%d", &num); getchar();

    for(t=1; t<=num; t++) {
        gets(str);

        for (i=0; i<strlen(str); i++) str[i]=toupper(str[i]);
        for(i=0; i<strlen(str); i++) {
            if (str[i]>='A' && str[i]<='Z') frequency[str[i]-65]++ ;
        }
    }

    for(i=0; i<25; i++) {
        for(k=i+1; k<26; k++) {
            if (frequency[k]>frequency[i]) {
                temp=frequency[i]; frequency[i]=frequency[k]; frequency[k]=temp;
                temp=alphabet[i]; alphabet[i]=alphabet[k]; alphabet[k]=temp;
            }
        }
    }

    for (i=0; i<26; i++) {
        for(j=0; j<i; j++) {
            if (frequency[i]==frequency[j]) break;
        }
        if (j==i) nums[ind++]=frequency[i];
    }

    for(i=0; i<ind; i++) {
        p=0;
        for(j=0; j<26; j++) {
            if (nums[i]==frequency[j]) sames[p++]=alphabet[j];
        }

        for(k=0; k<p-1; k++) {
            for(m=k+1; m<p; m++) {
                if (sames[m]<sames[k]) { temp=sames[k]; sames[k]=sames[m]; sames[m]=temp; }
            }
        }

        p=0;
        for(k=0; k<26; k++) {
            if (frequency[k]==nums[i]) alphabet[k]=sames[p++];
        }
    }

    for(i=0; i<26; i++) if (frequency[i]!=0) printf("%c %d\n", alphabet[i], frequency[i]);

    return 0;
}

