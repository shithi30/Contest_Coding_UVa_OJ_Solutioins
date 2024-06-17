#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int seq, cost;
    node(int cons_seq, int cons_cost) {
        seq=cons_seq; cost=cons_cost;
    }
};

struct edge {
    int v, w;
    edge(int cons_v, int cons_w) {
        v=cons_v; w=cons_w;
    }
};

bool operator< (node a, node b)
{
    return a.cost>b.cost;
}

int dist[20000], n;
vector <edge> adj[20000];

void dijkstra(int src, int dest, int t)
{
    priority_queue <node> PQ;

    for(int v=0; v<n; v++) dist[v]=9999999;
    dist[src]=0;

    PQ.push(node(src, 0));

    while(PQ.empty()!=1) {
        node u=PQ.top(); PQ.pop();

        if(dist[u.seq]!=u.cost) continue;

        if(u.seq==dest) { printf("Case #%d: %d\n", t, u.cost); return; }

        for(int i=0; i<adj[u.seq].size(); i++) {
            edge e=adj[u.seq][i];
            if(dist[e.v]>u.cost+e.w) {
                dist[e.v]=u.cost+e.w;
                PQ.push(node(e.v, dist[e.v]));
            }
        }
    }

    printf("Case #%d: unreachable\n", t);
}

int main ()
{
    int test_case, t, edges, node1, node2, weight, start, end;

    scanf("%d", &test_case);

    for(t=1; t<=test_case; t++) {
        scanf("%d%d%d%d", &n, &edges, &start, &end);
        for(int i=0; i<edges; i++) {
            scanf("%d%d%d", &node1, &node2, &weight);
            adj[node1].push_back(edge(node2, weight));
            adj[node2].push_back(edge(node1, weight));
        }

        dijkstra(start, end, t);
        for(int i=0; i<n; i++) adj[i].clear();
    }

    return 0;
}
