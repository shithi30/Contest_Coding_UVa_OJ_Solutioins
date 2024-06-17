#include <cstdio>
#include <vector>

using namespace std;

int m, n, weight[998001], dist[998001], parent[998001], nodes;

int get_cost()
{
    int p=nodes-1, cost=0;

    while(1) {
        cost=cost+weight[p];
        if (p==0) break;
        p=parent[p];
    }

    return cost;
}

void get_adj(int u, vector <int> &adj)
{
    int n;

    n=u-m;
    if (n>=0) adj.push_back(n);

    n=u+m;
    if (n<nodes) adj.push_back(n);

    n=u-1;
    if (u%m!=0) adj.push_back(n);

    n=u+1;
    if ((u+1)%m!=0) adj.push_back(n);
}

int if_all_visited(vector <int> q)
{
    for(int i=0; i<nodes; i++) if(q[i]!=-1) return 0;
    return 1;
}

int extract_min(vector <int> &q)
{
    int node_with_min_dist, min_dist=999999, i, ind;

    for(i=0; i<nodes; i++) {
        if (q[i]==-1) continue;
        if (dist[q[i]]<=min_dist) { min_dist=dist[q[i]]; node_with_min_dist=q[i]; ind=i; }
    }
    q[ind]=-1;

    return node_with_min_dist;
}

void dijkstra()
{
    int u, v;

    for(v=0; v<nodes; v++) { dist[v]=999999; parent[v]=-1; }
    dist[0]=weight[0];

    vector <int> q, adj;

    for(v=0; v<nodes; v++) q.push_back(v);

    while (if_all_visited(q)!=1) {
        u=extract_min(q);
        get_adj(u, adj);
        for(v=0; v<adj.size(); v++) {
            if (dist[adj[v]]>dist[u]+weight[adj[v]]) {
                dist[adj[v]]=dist[u]+weight[adj[v]];
                parent[adj[v]]=u;
            }
        }
    }
}

int main ()
{
    int i, test_case, t;

    scanf("%d", &test_case);

    for (t=0; t<test_case; t++) {
        scanf("%d%d", &n, &m);
        nodes=m*n;

        for(i=0; i<nodes; i++) scanf("%d", &weight[i]);

        dijkstra();

        printf("%d\n", get_cost());
    }

    return 0;
}
