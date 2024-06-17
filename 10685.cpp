#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

int max_chain_size;
map <string, string> creature_root;
map <string, int> creature_size;

string get_root(string creature)
{
    string root; stack <string> s;

    while(1) {
        if(creature==creature_root[creature]) { root=creature; break; }
        else { s.push(creature); creature=creature_root[creature]; }
    }
    while(!s.empty()) { creature_root[s.top()]=root; s.pop(); }

    return root;
}

void unite_in_chain(string creature1, string creature2)
{
    string root_creature1, root_creature2;

    root_creature1=get_root(creature1); root_creature2=get_root(creature2);
    if(root_creature1!=root_creature2) {
        creature_root[root_creature1]=root_creature2;
        creature_size[root_creature2]+=creature_size[root_creature1];
        creature_size[root_creature1]=0;
        if(max_chain_size<creature_size[root_creature2]) max_chain_size=creature_size[root_creature2];
    }
}

int main ()
{
    int creatures, relations, i;
    string creature, creature1, creature2;

    while(1) {
        cin>>creatures>>relations;

        if(creatures==0 && relations==0) break;
        max_chain_size=1; creature_root.clear(); creature_size.clear();

        for(i=0; i<creatures; i++) {
            cin>>creature;
            creature_root[creature]=creature;
            creature_size[creature]=1;
        }
        for(i=0; i<relations; i++) {
            cin>>creature1>>creature2;
            unite_in_chain(creature1, creature2);
        }

        cout<<max_chain_size<<endl;
    }

    return 0;
}
