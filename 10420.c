#include <stdio.h>
#include <string.h>

void cut_pad (char ara[100])
{
    int i, j=0;
    char ara2[100];

    for (i=0; i<strlen(ara); i++) if ((ara[i]>='A' && ara[i]<='Z') || (ara[i]>='a' && ara[i]<='z')) break;

    for ( ; i<strlen(ara); i++) ara2[j++]=ara[i];
    ara2[j]='\0';

    strcpy(ara, ara2);
}

int main ()
{
    int num, ind, i, j, k, girls[2000], temp2;
    char country[2000][100], area[75], str[1000], temp1[100];

    scanf("%d", &num);
    getchar();

    ind=0;

    for(i=0; i<75; i++) girls[i]=0;

    for(i=0; i<num; i++) {
        gets(str);
        cut_pad(str);

        j=0;

        for(k=0; ((str[k]>='A' && str[k]<='Z') || (str[k]>='a' && str[k]<='z')); k++) area[j++]=str[k];
        area[j]='\0';

        for(j=0; j<ind; j++) if (strcmp(country[j], area)==0) break;
        if (j==ind) strcpy(country[ind++], area);

        girls[j]++;
    }

    for (i=0; i<(ind-1); i++) {
        for(j=i+1; j<ind; j++) {
            if (strcmp(country[i], country[j])>0) {
                strcpy(temp1, country[i]); strcpy(country[i], country[j]); strcpy(country[j], temp1);
                temp2=girls[i]; girls[i]=girls[j]; girls[j]=temp2;
            }
        }
    }

    for(i=0; i<ind; i++) printf("%s %d\n", country[i], girls[i]);

    return 0;
}
