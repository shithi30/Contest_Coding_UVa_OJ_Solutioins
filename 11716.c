#include <stdio.h>
#include <string.h>
#include <math.h>

int whether_sqr(int a)
{
    if (sqrt(a)==(double)((int)sqrt(a))) return 1;
    return 0;
}

int main ()
{
    int test, t, i, j, k, elements;
    char str[10000];
    char decipher[100][100];
    char buff;

    scanf("%d", &test);
    buff=getchar();

    for(t=1; t<=test; t++) {
        gets(str);
        k=0;
        if (whether_sqr(strlen(str))==0) { printf("INVALID\n"); continue; }
        elements=(int)sqrt(strlen(str));
        for(i=0; i<elements; i++) {
            for(j=0; j<elements; j++) {
                decipher[i][j]=str[k];
                k++;
            }
        }
        for(j=0; j<elements; j++) {
            for(i=0; i<elements; i++) {
                printf("%c", decipher[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
