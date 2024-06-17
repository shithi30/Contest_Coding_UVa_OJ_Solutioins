#include <cstdio>
#include <vector>

using namespace std;

int graph[100][100], parent[100], dist[100], nodes;

int extract_min(vector <int> &q)
{
    int node_with_min_dist, min_dist=9999, i, ind;

    for(i=0; i<nodes; i++) {
        if(q[i]==-1) continue;
        if (dist[q[i]]<=min_dist) { min_dist=dist[q[i]]; node_with_min_dist=q[i]; ind=i; }
    }
    q[ind]=-1;

    return node_with_min_dist;
 }

int if_all_visited(vector <int> q)
{
    for(int i=0; i<nodes; i++) if(q[i]!=-1) return 0;
    return 1;
}

void dijkstra(int src)
{
    int u, v;

    for(v=0; v<nodes; v++) { dist[v]=9999; parent[v]=-1; }
    dist[src]=0;

    vector <int> q;
    for(v=0; v<nodes; v++) q.push_back(v);

    while(if_all_visited(q)!=1) {
        u=extract_min(q);
        for(v=0; v<nodes; v++) {
            if (graph[u][v]!=0) {
                if (dist[v]>dist[u]+graph[u][v]) {
                    dist[v]=dist[u]+graph[u][v];
                    parent[v]=u;
                }
            }
        }
    }
}

int main ()
{
    int from, to, test_case, t, time, exit_node, edges, e, i, j, count;

    scanf("%d", &test_case);
    getchar();

    for (t=1; t<=test_case; t++) {

        scanf("%d%d%d%d", &nodes, &exit_node, &time, &edges);

        for(i=0; i<nodes; i++) for(j=0; j<nodes; j++) graph[i][j]=0; count=0;

        for(e=1; e<=edges; e++) {
            scanf("%d%d", &from, &to);
            scanf("%d", &graph[to-1][from-1]);
        }

        dijkstra(exit_node-1);

        for (int i=0; i<nodes; i++) if (dist[i]<=time) count++;

        if(t!=test_case) printf("%d\n\n", count);
        else printf("%d\n", count);
        getchar();
    }

    return 0;
}
