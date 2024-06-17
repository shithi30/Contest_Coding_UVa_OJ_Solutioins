#include <iostream>
using namespace std;

int main ()
{
    int d1, d2, d3, d4, total;

    while(1) {
        cin>>d1>>d2>>d3>>d4;
        if(d1==0 && d2==0 && d3==0 && d4==0) break;

        total=360+360;
        if(d1<d2) total+=((40+d1)-d2)*9;
        else total+=(d1-d2)*9;

        total+=360;
        if(d3<d2) total+=((40+d3)-d2)*9;
        else total+=(d3-d2)*9;

        if(d3<d4) total+=((40+d3)-d4)*9;
        else total+=(d3-d4)*9;

        cout<<total<<endl;
    }

    return 0;
}
