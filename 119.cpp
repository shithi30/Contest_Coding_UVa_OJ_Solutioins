#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main ()
{
    int friends, i, amount, give_to, j, div, rem, test=0;
    string names[20], name;
    map <string, int> friend_worth;

    while(scanf("%d", &friends)!=EOF) {
        test++;
        friend_worth.clear();

        for(i=0; i<friends; i++) {
            cin>>names[i];
            friend_worth[names[i]]=0;
        }
        for(i=0; i<friends; i++) {
            cin>>name>>amount>>give_to;
            if(give_to==0) continue;
            div=amount/give_to; rem=amount%give_to;
            friend_worth[name]=friend_worth[name]+rem-amount;
            for(j=0; j<give_to; j++) {
                cin>>name;
                friend_worth[name]+=div;
            }
        }

        if(test!=1) cout<<endl;
        for(i=0; i<friends; i++) cout<<names[i]<<" "<<friend_worth[names[i]]<<endl;
    }

    return 0;
}
