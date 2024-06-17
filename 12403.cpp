#include <string>
#include <iostream>

using namespace std;

int main ()
{
    string operation;
    int amount, current=0, ops, i;

    cin>>ops;
    for(i=0; i<ops; i++) {
        cin>>operation;
        if(operation=="donate") {
            cin>>amount;
            current+=amount;
        }
        else cout<<current<<endl;
    }

    return 0;
}
