#include <stdio.h>
#include <string.h>

int main ()
{
    char ara[47]= { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
        'P', '[', ']', '\\', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/' };
    char str[200];
    int i, j;

    while(gets(str)) {
        for(i=0; i<strlen(str); i++) {
            if (str[i]==' ') { printf(" "); continue; }
            for(j=0; j<47; j++) {
                if (str[i]==ara[j]) printf("%c", ara[j-1]);
            }
        }
        printf("\n");
    }
    return 0;
}
