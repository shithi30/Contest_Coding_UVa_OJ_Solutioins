#include <stdio.h>
#include <string.h>

int main ()
{
    int i, cas, k, stroke, sum, num;
    char ara[100];

    scanf("%d", &cas);
    getchar();
    for(i=0; i<cas; i++) {
        gets(ara);
        sum=0;
        for (k=0; k<strlen(ara); k++) {
            if (ara[k]>='a' && ara[k]<='r') {
                num=ara[k]-67;
                stroke=num%3+1;
            }
            else {
                switch (ara[k]) {
                    case ' ' : stroke=1; break;
                    case 's' : stroke=4; break;
                    case 't' : stroke=1; break;
                    case 'u' : stroke=2; break;
                    case 'v' : stroke=3; break;
                    case 'w' : stroke=1; break;
                    case 'x' : stroke=2; break;
                    case 'y' : stroke=3; break;
                    case 'z' : stroke=4; break;
                }
            }
            sum += stroke;
        }
        printf("Case #%d: %d\n", i+1, sum);
    }

    return 0;
}
