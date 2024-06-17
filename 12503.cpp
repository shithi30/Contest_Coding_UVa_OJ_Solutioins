#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
    int cases, t, commands, i, pos, seq;
    string command;
    vector <string> instructions;

    cin>>cases;
    for(t=0; t<cases; t++) {
        cin>>commands;

        pos=0; instructions.clear(); instructions.push_back("none");
        for(i=1; i<=commands; i++) {
            cin>>command;

            if(command=="LEFT") instructions.push_back(command);
            else if(command=="RIGHT") instructions.push_back(command);
            else {
                cin>>command>>seq;
                instructions.push_back(instructions[seq]);
            }

            if(instructions[i]=="LEFT") pos--;
            else pos++;
        }

        cout<<pos<<endl;
    }

    return 0;
}
