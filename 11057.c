#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main ()
{
    unsigned int books, *prices, money, i, j, a, b, c, big, small;

    while (scanf("%d", &books)!=EOF) {

        prices=(int)malloc(books*sizeof(int));

        for (i=0; i<books; i++) scanf("%d", &prices[i]);
        scanf("%d", &money);

        c=money;
        for (i=0; i<books; i++) {
            for (j=0; j<books; j++) {
                if (i==j) continue;
                if((prices[i]+prices[j]==money)&&(abs(prices[i]-prices[j])<c)) { a=prices[i]; b=prices[j]; c=abs(a-b); }
            }
        }
        if (a>=b) { big=a; small=b; }
        else { big=b; small=a; }

        printf ("Peter should buy books whose prices are %d and %d.\n\n", small, big);

        free(prices);
    }
    return 0;
}
