#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int p, i, j, if_finished=0;
    string people[100], song[16]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    cin>>p; for(i=0; i<p; i++) cin>>people[i];

    j=0;
    while(1) {
        for(i=0; i<16; i++) {
            cout<<people[j]<<": "<<song[i]<<endl;
            j++;
            if(j==p) { if_finished=1; j=0; }
        }
        if(if_finished==1) break;
    }

    return 0;
}
