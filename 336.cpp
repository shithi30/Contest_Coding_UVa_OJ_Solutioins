#include <iostream>
#include <queue>
#include <vector>

#define white 1
#define gray 2
#define black 3

using namespace std;

int graph[35][35], color[35], dist[35];
vector <int> labels;

int if_exists(int node_label)
{
    int i, s=labels.size();

    for(i=0; i<s; i++) {
        if(node_label==labels[i]) return 1;
    }
    return 0;
}

int check_in_labels(int node_label)
{
    int i, s=labels.size();

    for(i=0; i<s; i++) {
        if(node_label==labels[i]) return i;
    }
    if(i==s) {
        labels.push_back(node_label);
        return s;
    }
}

int BFS_get_unreachables(int assistive_src, int ttl)
{
    int u, v, nodes, i, unreachables=0, visiteds=0; queue<int> q;
    nodes=labels.size();

    for(i=0; i<nodes; i++) { color[i]=white; dist[i]=999999; }
    color[assistive_src]=gray; dist[assistive_src]=0;
    q.push(assistive_src);

    while(!q.empty()) {
        u=q.front(); q.pop();

        for(v=0; v<nodes; v++) {
            if(graph[u][v]==1) {
                if(color[v]==white) {
                    color[v]=gray; dist[v]=dist[u]+1; q.push(v);
                }
            }
        }

        color[u]=black;
        if(dist[u]>ttl) unreachables++;
        visiteds++;
    }

    unreachables=unreachables+(nodes-visiteds);
    return unreachables;
}

int main ()
{
    int edges, i, j, unreachables, src, assistive_src, ttl, from, to, test=0;

    while(1) {
        cin>>edges;

        if(edges==0) break;
        for(i=0; i<35; i++) for(j=0; j<35; j++) graph[i][j]=0; labels.clear();

        for(i=0; i<edges; i++) {
            cin>>from>>to;
            graph[check_in_labels(from)][check_in_labels(to)]=graph[check_in_labels(to)][check_in_labels(from)]=1;
        }

        while(1) {
            cin>>src>>ttl;
            if(src==0 && ttl==0) break;
            test++;
            if(if_exists(src)) {
                assistive_src=check_in_labels(src);
                unreachables=BFS_get_unreachables(assistive_src, ttl);
                cout<<"Case "<<test<<": "<<unreachables<<" nodes not reachable from node "<<src<<" with TTL = "<<ttl<<"."<<endl;
            }
            else cout<<"Case "<<test<<": "<<labels.size()<<" nodes not reachable from node "<<src<<" with TTL = "<<ttl<<"."<<endl;
        }
    }

    return 0;
}
