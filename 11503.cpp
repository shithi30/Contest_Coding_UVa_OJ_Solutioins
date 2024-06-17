#include <iostream>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;

map <string, string> friend_root;
map <string, int> friend_size;
set <string> friends;

string get_root(string frnd)
{
    string root; stack <string> s;

    while(1) {
        if(friend_root[frnd]==frnd) { root=frnd; break; }
        else { s.push(frnd); frnd=friend_root[frnd]; }
    }
    while(!s.empty()) { friend_root[s.top()]=frnd; s.pop(); }

    return root;
}

void unite_friends(string friend1, string friend2)
{
    string root_friend1, root_friend2;

    root_friend1=get_root(friend1); root_friend2=get_root(friend2);
    if(root_friend1!=root_friend2) {
        friend_root[root_friend1]=root_friend2;
        friend_size[root_friend2]+=friend_size[root_friend1];
        friend_size[root_friend1]=0;
        cout<<friend_size[root_friend2]<<endl;
    }
    else cout<<friend_size[root_friend1]<<endl;
}

int new_friend(string frnd)
{
    int prev_size=friends.size(), present_size;

    friends.insert(frnd);
    present_size=friends.size();

    if(prev_size==present_size) return 0;
    return 1;
}

int main ()
{
    int i, tests, t, f;
    string friend1, friend2;

    cin>>tests;
    for(t=0; t<tests; t++) {
        friend_root.clear(); friend_size.clear(); friends.clear();
        cin>>f;
        for(i=0; i<f; i++) {
            cin>>friend1>>friend2;
            if(new_friend(friend1)) { friend_root[friend1]=friend1; friend_size[friend1]=1; }
            if(new_friend(friend2)) { friend_root[friend2]=friend2; friend_size[friend2]=1; }
            unite_friends(friend1, friend2);
        }
    }

    return 0;
}
