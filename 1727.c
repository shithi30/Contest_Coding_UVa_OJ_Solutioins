#include <stdio.h>
#include <string.h>

int main ()
{
    int test, t, iter, i, ind, count;
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char mon[25], bar[25];
    char months[12][25] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
    char bars[7][25] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

    scanf("%d", &test);

    for (t=1; t<=test; t++) {
        scanf("%s", mon);
        scanf("%s", bar);

        count=0;

        for(i=0; i<12; i++) if (strcmp(mon, months[i])==0) iter=days[i];
        for(i=0; i<7; i++)  if (strcmp(bar, bars[i])==0) ind=i;

        if (ind==5 || ind==6) count++;

        for(i=2; i<=iter; i++) {
            ind++;
            if (ind==7) ind=0;
            if (ind==5 || ind==6) count++;
        }

        printf("%d\n", count);
    }

    return 0;
}
