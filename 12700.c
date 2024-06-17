#include <stdio.h>
#include <string.h>

int main ()
{
    int chars, test, te, i, b, w, a, t;
    char results[25];
    char buffer;

    scanf("%d", &test);

    for(te=1; te<=test; te++) {

        scanf("%d", &chars);
        buffer=getchar();
        gets(results);

        b=0; a=0; w=0; t=0;

        for(i=0; i<chars; i++) {
            if (results[i]=='B') b++;
            else if (results[i]=='W') w++;
            else if (results[i]=='A') a++;
            else if (results[i]=='T') t++;
        }

        printf("Case %d: ", te);
        if (a==chars) printf("ABANDONED\n");
        else if (b==w) printf("DRAW %d %d\n", w, t);
        else if ((b>w) && ((chars-b)==a)) printf("BANGLAWASH\n");
        else if ((w>b) && ((chars-w)==a)) printf("WHITEWASH\n");
        else if (w>b) printf("WWW %d - %d\n", w, b);
        else if (b>w) printf("BANGLADESH %d - %d\n", b, w);
    }
    return 0;
}
