#include <stdio.h>
#include <string.h>

int main ()
{
    int i, test, t, sum, zeros;
    char str[85], buffer;
    scanf("%d", &test);
    buffer=getchar();

    for(t=1; t<=test; t++) {
        gets(str);
        sum=0; zeros=1;
        for(i=0; i<strlen(str); i++) {
            if (str[i]=='O') { sum=sum+zeros; zeros++; }
            else if (str[i]=='X') { zeros=1; }
        }
        printf("%d\n", sum);
    }
    return 0;
}
