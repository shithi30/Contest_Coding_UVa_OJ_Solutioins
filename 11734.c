#include <stdio.h>
#include <string.h>

int main ()
{
    int test, t, i, j, k;
    char team[200], judge[50], team2[50];
    char buffer;

    scanf("%d", &test);
    buffer=getchar();

    for(t=1; t<=test; t++) {

        gets(team);
        gets(judge);

        if (strlen(team)==strlen(judge)) {
            for (i=0; i<strlen(team); i++) {
                if (team[i]!=judge[i]) break;
            }
            if (i==strlen(team)) { printf("Case %d: Yes\n", t); continue; }
            else { printf("Case %d: Wrong Answer\n", t); continue; }
        }

        k=0;
        for (i=0; i<strlen(team); i++) {
            if (team[i]!=' ') { team2[k]=team[i]; k++; }
        }
        team2[k]='\0';

        if (strlen(team2)==strlen(judge)) {
            for (i=0; i<strlen(team2); i++) {
                if (team2[i]!=judge[i]) break;
            }
            if (i==strlen(team2)) { printf("Case %d: Output Format Error\n", t); continue; }
            printf("Case %d: Wrong Answer\n", t);
        }
        else printf("Case %d: Wrong Answer\n", t);
    }
    return 0;
}
