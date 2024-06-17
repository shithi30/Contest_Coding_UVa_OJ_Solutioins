#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main ()
{
    int tests, t;
    double length, green, red, total;

    cin>>tests;

    for(t=1; t<=tests; t++) {
        cin>>length;
        total=length*(length*.6);
        red=acos(-1)*(length*.2)*(length*.2);
        printf("%.2lf %.2lf\n", red, total-red);
    }

    return 0;
}
