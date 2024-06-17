#include <string>
#include <iostream>
using namespace std;

int main ()
{
    string res;
    int tests, t, s;

    cin>>tests;
    for(t=0; t<tests; t++) {
        cin>>res;

        s=res.size();
        if(res=="4" || res=="1" || res=="78") cout<<"+"<<endl;
        else if(res[s-2]=='3' && res[s-1]=='5') cout<<"-"<<endl;
        else if(res[0]=='9' && res[s-1]=='4') cout<<"*"<<endl;
        else if(res[0]=='1' && res[1]=='9' && res[2]=='0') cout<<"?"<<endl;
        else cout<<"?"<<endl;
    }

    return 0;
}
