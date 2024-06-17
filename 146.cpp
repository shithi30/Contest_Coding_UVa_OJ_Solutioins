#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    string v;

    while(cin>>v) {
        if (v[0]=='#') break;

        if (next_permutation(v.begin(), v.end())) cout<<v<<endl;
        else cout<<"No Successor\n";
    }

    return 0;
}
