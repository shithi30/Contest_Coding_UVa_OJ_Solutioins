#include <iostream>
using namespace std;

int main ()
{
    int availables, i, needed[100], created[100], tests=0;

    while(1) {
        cin>>availables;
        if(availables<0) break; tests++;
        for(i=1; i<=12; i++) cin>>created[i];
        for(i=1; i<=12; i++) cin>>needed[i];

        cout<<"Case "<<tests<<":"<<endl;
        for(i=1; i<=12; i++) {
            availables=availables-needed[i];
            if(availables<0) {
                cout<<"No problem. :("<<endl;
                availables=availables+needed[i];
            }
            else cout<<"No problem! :D"<<endl;
            availables=availables+created[i];
        }
    }

    return 0;
}
