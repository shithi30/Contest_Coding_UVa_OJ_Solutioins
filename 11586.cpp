#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int tests, t, males, females, size, j;
    string str;

    cin>>tests; getchar();
    for(t=0; t<tests; t++) {
        getline(cin, str);
        males=females=0;
        size=str.size();
        for(j=0; j<size; j++) {
            if(str[j]=='M') males++;
            else if(str[j]=='F') females++;
        }

        if(males==females && males!=1) cout<<"LOOP"<<endl;
        else cout<<"NO LOOP"<<endl;
    }

    return 0;
}
