#include <iostream>
using namespace std;

int main ()
{
    int i, j, lines, groups[10], if_ok, k;

    cin>>lines;
    cout<<"Lumberjacks:"<<endl;
    for(i=0; i<lines; i++) {
       if_ok=0;
       for(j=0; j<10; j++) cin>>groups[j];

       for(k=1; k<10; k++) {
           if(groups[k-1]<=groups[k]) if_ok=1;
           else { if_ok=0; break; }
       }
       if(if_ok==1) { cout<<"Ordered"<<endl; continue; }

       for(k=1; k<10; k++) {
           if(groups[k-1]>=groups[k]) if_ok=1;
           else { if_ok=0; break; }
       }
       if(if_ok==1) { cout<<"Ordered"<<endl; continue; }

       cout<<"Unordered"<<endl;
    }

    return 0;
}

