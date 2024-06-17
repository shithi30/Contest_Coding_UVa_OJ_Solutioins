#include <iostream>
using namespace std;

int main ()
{
    int cases, t, cols, i, start, end, prev_gap, pres_gap, if_ok;

    cin>>cases;
    for(t=1; t<=cases; t++) {
        cin>>cols>>start>>end;
        prev_gap=start-end;
        if_ok=1;
        for(i=1; i<cols; i++) {
            cin>>start>>end;
            pres_gap=start-end;
            if(prev_gap!=pres_gap) if_ok=0;
        }
        if(t!=cases) {
            if(if_ok==1) cout<<"yes"<<endl<<endl;
            else cout<<"no"<<endl<<endl;
        }
        else {
            if(if_ok==1) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }

    return 0;
}

