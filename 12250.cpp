#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string greet;
    int test=0;

    while(1) {
        cin>>greet;
        if(greet=="#") break;
        test++;

        if(greet=="HELLO") cout<<"Case "<<test<<": "<<"ENGLISH"<<endl;
        else if(greet=="HOLA") cout<<"Case "<<test<<": "<<"SPANISH"<<endl;
        else if(greet=="HALLO") cout<<"Case "<<test<<": "<<"GERMAN"<<endl;
        else if(greet=="BONJOUR") cout<<"Case "<<test<<": "<<"FRENCH"<<endl;
        else if(greet=="CIAO") cout<<"Case "<<test<<": "<<"ITALIAN"<<endl;
        else if(greet=="ZDRAVSTVUJTE") cout<<"Case "<<test<<": "<<"RUSSIAN"<<endl;
        else cout<<"Case "<<test<<": "<<"UNKNOWN"<<endl;
    }

    return 0;
}
