#include <iostream>
#include <stack>

using namespace std;

int max_circle, citizen_friend[35000], citizen_circle[35000];

int get_friend(int citizen)
{
    stack <int> s; int frnd;

    while(1) {
        if(citizen_friend[citizen]==citizen) { frnd=citizen; break; }
        else { s.push(citizen); citizen=citizen_friend[citizen]; }
    }
    while(!s.empty()) { citizen_friend[s.top()]=frnd; s.pop(); }

    return frnd;
}

void make_friends(int citizen1, int citizen2)
{
    int friend_citizen1, friend_citizen2;

    friend_citizen1=get_friend(citizen1); friend_citizen2=get_friend(citizen2);
    if(friend_citizen1!=friend_citizen2) {
        citizen_friend[friend_citizen1]=friend_citizen2;
        citizen_circle[friend_citizen2]=citizen_circle[friend_citizen2]+citizen_circle[friend_citizen1]; citizen_circle[friend_citizen1]=0;
        if(max_circle<citizen_circle[friend_citizen2]) max_circle=citizen_circle[friend_citizen2];
    }
}

int main ()
{
    int citizens, i, pairs, friend1, friend2, tests, t;

    cin>>tests;
    for(t=0; t<tests; t++) {
        cin>>citizens>>pairs; max_circle=1;

        for(i=1; i<=citizens; i++) { citizen_circle[i]=1; citizen_friend[i]=i; }

        for(i=0; i<pairs; i++) {
            cin>>friend1>>friend2;
            make_friends(friend1, friend2);
        }

        cout<<max_circle<<endl;
    }

    return 0;
}
