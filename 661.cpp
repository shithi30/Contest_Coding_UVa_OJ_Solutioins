#include <iostream>
using namespace std;

int main ()
{
    int devices, commands, capacity, i, consumptions[25], states[25], to_toggle, total_consumption, highest_consumption, j, exceed, seq=0;

    while(1) {
        cin>>devices>>commands>>capacity; if(devices==0 && commands==0 && capacity==0) break; seq++;
        for(i=1; i<=devices; i++) cin>>consumptions[i];

        for(i=1; i<=devices; i++) states[i]=0;
        highest_consumption=exceed=0;

        for(i=0; i<commands; i++) {
            cin>>to_toggle;

            if(states[to_toggle]==0) states[to_toggle]=consumptions[to_toggle];
            else states[to_toggle]=0;

            total_consumption=0; for(j=1; j<=devices; j++) total_consumption+=states[j];
            if(total_consumption>capacity) exceed=1;
            else if(total_consumption>highest_consumption) highest_consumption=total_consumption;
        }

        if(exceed==1) cout<<"Sequence "<<seq<<endl<<"Fuse was blown."<<endl<<endl;
        else cout<<"Sequence "<<seq<<endl<<"Fuse was not blown."<<endl<<"Maximal power consumption was "<<highest_consumption<<" amperes."<<endl<<endl;
    }

    return 0;
}
