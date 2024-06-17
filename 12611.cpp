#include <iostream>
using namespace std;

int main ()
{
    int tests, t;
    double radius, unit;

    cin>>tests;
    for(t=1; t<=tests; t++) {
        cin>>radius;

        unit=radius/20;

        cout<<"Case "<<t<<":"<<endl;
        cout<<(-45*unit)<<" "<<(30*unit)<<endl;
        cout<<(55*unit)<<" "<<(30*unit)<<endl;
        cout<<(55*unit)<<" "<<(-30*unit)<<endl;
        cout<<(-45*unit)<<" "<<(-30*unit)<<endl;
    }

    return 0;
}
