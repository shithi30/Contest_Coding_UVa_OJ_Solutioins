#include <iostream>
#include <queue>

#define white 1
#define gray 2
#define black 3

#define blue 4
#define red 5

using namespace std;

int graph[200][200], color[200], bipertite[200], nodes, edges;

int if_bipertite()
{
    int i, u, v;

    for(i=0; i<nodes; i++) color[i]=white;
    color[0]=gray; bipertite[0]=red;

    queue <int> q; q.push(0);

    while(!q.empty()) {
        u=q.front(); q.pop();

        for(v=0; v<nodes; v++) {
            if(graph[u][v]==1) {
                if(color[v]==white) {
                    color[v]=gray; q.push(v);
                    if(bipertite[u]==red) bipertite[v]=blue;
                    else if(bipertite[u]==blue) bipertite[v]=red;
                }
                if(bipertite[u]==bipertite[v]) return 0;
            }
        }

        color[u]=black;
    }

    return 1;
}

int main ()
{
    int i, j, from, to;

    while(1) {
        cin>>nodes;
        if(nodes==0) break;
        cin>>edges;
        for(i=0; i<nodes; i++) for(j=0; j<nodes; j++) graph[i][j]=0;
        for(i=0; i<edges; i++) {
            cin>>from>>to;
            graph[from][to]=graph[to][from]=1;
        }

        if(if_bipertite()) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }

    return 0;
}
