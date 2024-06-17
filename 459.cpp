#include <iostream>
#include <queue>
#include <string>

#define white 1
#define gray 2
#define black 3

using namespace std;

int nodes, color[100], graph[100][100];

void BFS(int src)
{
    int u, v;

    queue <int> q; q.push(src);

    while(q.empty()!=1) {
        u=q.front(); q.pop();
        for(v=0; v<nodes; v++) {
            if(graph[u][v]==1) {
                if(color[v]==white) { color[v]=gray; q.push(v); }
            }
        }
        color[u]=black;
    }
}

int main ()
{
    int test_case, t, node1, node2, count, i, j, v;
    string str;

    cin>>test_case; cin.ignore(); cin.ignore();

    for(t=1; t<=test_case; t++) {

        getline(cin, str); nodes=str[0]-64;

        for(i=0; i<nodes; i++) for(j=0; j<nodes; j++) graph[i][j]=0;
        for(v=0; v<nodes; v++) color[v]=white;
        count=0;

        for( ; ; ) {
            getline(cin, str);
            if(str.size()==0) break;
            node1=str[0]-65;
            node2=str[1]-65;
            graph[node1][node2]=graph[node2][node1]=1;
        }

        for(i=0; i<nodes; i++) {
            if(color[i]==white) {
                BFS(i);
                count++;
            }
        }

        if(t!=test_case) cout<<count<<endl<<endl;
        else cout<<count<<endl;
    }

    return 0;
}
