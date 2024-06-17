#include <stdio.h>
#include <string.h>

int if_vowel(char ch)
{
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return 1;
    return 0;
}

int main ()
{
    int regular, irregular, i, j, k, flag;
    char irregulars[120][25], food[25], buffer;

    while(scanf("%d%d", &irregular, &regular)==2) {

        for(i=0; i<(2*irregular); i++) scanf("%s", irregulars[i]);
        buffer=getchar();

        for(j=0; j<regular; j++) {
            gets(food);
            flag=0;
            for(k=0; k<i; k++) {
                    if (strcmp(food, irregulars[k])==0) { puts(irregulars[k+1]); flag=1; break; }
            }
            if (flag==1) continue;
            else if (food[strlen(food)-1]=='y' && if_vowel(food[strlen(food)-2])) { printf("%ss\n", food); continue; }
            else if (food[strlen(food)-1]=='y') {
                for(k=0; k<(strlen(food)-1); k++) printf("%c", food[k]);
                printf("ies\n");
                continue;
            }
            else if (food[strlen(food)-1]=='o'||food[strlen(food)-1]=='s'||food[strlen(food)-1]=='x'||(food[strlen(food)-2]=='c'&&food[strlen(food)-1]=='h')||(food[strlen(food)-2]=='s'&&food[strlen(food)-1]=='h')) {
                printf("%ses\n", food); continue;
            }
            else printf("%ss\n", food);
        }
    }
    return 0;
}
