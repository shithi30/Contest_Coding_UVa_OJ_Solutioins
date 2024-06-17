#include <cstdio>
#include <vector>

using namespace std;

vector <int> from, to, weight;
int dist[1000], nodes, edges;

int bellman_ford(int src)
{
    int v, n, i, if_relaxed;

    for(v=0; v<nodes; v++) dist[v]=999999;
    dist[src]=0;

    for(n=1; n<nodes; n++) {
        if_relaxed=0;
        for(i=0; i<edges; i++) {
            if(dist[to[i]]>dist[from[i]]+weight[i]) {
                dist[to[i]]=dist[from[i]]+weight[i];
                if_relaxed=1;
            }
        }
        if(if_relaxed==0) break;
    }

    for(i=0; i<edges; i++) if(dist[to[i]]>dist[from[i]]+weight[i]) return 0;
    return 1;
}

int main ()
{
    int test_case, from_node, to_node, w, i, t;

    scanf("%d", &test_case);

    for(t=0; t<test_case; t++) {
        scanf("%d%d", &nodes, &edges);

        for(i=0; i<edges; i++) {
            scanf("%d%d%d", &from_node, &to_node, &w);
            from.push_back(from_node); to.push_back(to_node); weight.push_back(w);
        }

        if(bellman_ford(0))  printf("not possible\n");
        else printf("possible\n");

        from.clear(); to.clear(); weight.clear();
    }

    return 0;
}
