#include <stdio.h>
#include <string.h>

int main ()
{
    char smalls[26], caps[26], str[1000000];
    int small[26], cap[26], i, h, j;

    while (gets(str)) {

        h=-1;

        for (i=0; i<26; i++) {
            smalls[i]=i+97;
            caps[i]=65+i;
            small[i]=cap[i]=0;
        }

        for(i=0; i<strlen(str); i++) {
            if (str[i]>='A' && str[i]<='Z') { for (j=0; j<26; j++) if (str[i]==caps[j]) cap[j]++; }
            else if (str[i]>='a' && str[i]<='z') { for (j=0; j<26; j++) if (str[i]==smalls[j]) small[j]++; }
        }

        for (i=0; i<26; i++) if (cap[i]>h) h=cap[i];
        for (i=0; i<26; i++) if (small[i]>h) h=small[i];

        for (i=0; i<26; i++) if (h==cap[i]) printf("%c", caps[i]);
        for (i=0; i<26; i++) if (h==small[i]) printf("%c", smalls[i]);

        printf(" %d\n", h);
    }

    return 0;
}
