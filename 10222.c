#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char replace1[32]={ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.' };
    char replace2[32]={ 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>' };
    char str[100];
    int i, j, k;

    gets(str);

    for(i=0; i<strlen(str); i++) {
        if (str[i]==' ') { printf(" "); continue; }
        for(j=0; j<32; j++) {
            if (str[i]==replace1[j]) printf("%c", replace1[j-2]);
            else if (str[i]==replace2[j]) printf("%c", tolower(replace2[j-2]));
        }
    }
    printf("\n");

    return 0;
}
