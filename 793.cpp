#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int nodes_root[1000000];

int get_root(int node)
{
    int root; stack <int> s;

    while(1) {
        if(node==nodes_root[node]) { root=node; break; }
        else { s.push(node); node=nodes_root[node]; }
    }
    while(!s.empty()) { nodes_root[s.top()]=root; s.pop(); }

    return root;
}

void join_nodes(int node1, int node2)
{
    int root_node1, root_node2;

    root_node1=get_root(node1); root_node2=get_root(node2);
    if(root_node1!=root_node2) nodes_root[root_node1]=root_node2;
}

int main ()
{
    int i, nodes, node1, node2, root1, root2, yes, no, tests, t;
    char prompt;

    cin>>tests;
    for(t=1; t<=tests; t++) {
        if(t!=1) cout<<endl;

        cin>>nodes; getchar();

        yes=no=0; for(i=1; i<=nodes; i++) nodes_root[i]=i;

        while(1) {
            prompt=getchar();
            if(prompt==EOF || prompt=='\n') break;
            cin>>node1>>node2;
            if(prompt=='c') join_nodes(node1, node2);
            else {
                root1=get_root(node1); root2=get_root(node2);
                if(root1==root2) yes++;
                else no++;
            }
            if(getchar()==EOF) break;
        }

        cout<<yes<<","<<no<<endl;
    }

    return 0;
}
