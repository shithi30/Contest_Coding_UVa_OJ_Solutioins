#include <stdio.h>
#include <math.h>

int main ()
{
    int x, y, r;
    int test, t;
    double longest, shortest;

    scanf("%d", &test);
    for(t=1; t<=test; t++) {
        scanf("%d%d%d", &x, &y, &r);
        longest=(double)r+sqrt(x*x+y*y);
        shortest=(double)r-sqrt(x*x+y*y);
        printf("%0.2lf %0.2lf\n", shortest, longest);
    }
    return 0;
}
