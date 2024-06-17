#include <stdio.h>
#include <string.h>

int main ()
{
    char word[10];
    int test, t, mistake;
    char buffer;

    scanf("%d", &test);
    buffer=getchar();

    for(t=1; t<=test; t++) {
        gets(word);
        mistake=0;
        if (strlen(word)==5) { printf("3\n"); continue; }
        if (strlen(word)==3) {
            if (word[0]!='o') mistake=mistake+1;
            if (word[1]!='n') mistake=mistake+1;
            if (word[2]!='e') mistake=mistake+1;
            if (mistake<=1) { printf("1\n"); continue; }
            printf("2\n");
        }
    }
    return 0;
}
