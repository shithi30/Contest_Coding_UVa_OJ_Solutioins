#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int seq, cost;
    node (int cons_seq, int cons_cost) {
        seq=cons_seq; cost=cons_cost;
    }
};

struct edge {
    int v, w;
    edge (int cons_v, int cons_w) {
        v=cons_v; w=cons_w;
    }
};

bool operator< (node node1, node node2) {
    return node1.cost>node2.cost;
}

int visited[1000000], nodes, key[1000000];
vector <edge> adj_edges[1000000];

int prim()
{
    int new_cost=0, i, count_visiteds=0;

    for(i=0; i<nodes; i++) { key[i]=9999999; visited[i]=0; }
    key[0]=0;

    priority_queue <node> PQ; PQ.push(node(0, 0));

    while(!PQ.empty()) {
        node u=PQ.top(); PQ.pop(); if(visited[u.seq]) continue;

        int size_adj=adj_edges[u.seq].size();
        for(i=0; i<size_adj; i++) {
            edge e=adj_edges[u.seq][i];
            if (visited[e.v]) continue;
            if(key[e.v]>e.w) { key[e.v]=e.w; PQ.push(node(e.v, key[e.v])); }
        }

        visited[u.seq]=1; new_cost=new_cost+u.cost; count_visiteds++;

        if(count_visiteds==nodes) break;
    }

    return new_cost;
}

int main ()
{
    int node1, node2, weight, i, prev_cost, m, k, new_line=0;

    while(scanf("%d", &nodes)==1) {
        if(new_line==0) new_line=1;
        else printf("\n");

        prev_cost=0;

        for(i=1; i<nodes; i++) {
            scanf("%d%d%d", &node1, &node2, &weight);
            prev_cost=prev_cost+weight;
        }

        scanf("%d", &m);
        for(i=0; i<m; i++) {
            scanf("%d%d%d", &node1, &node2, &weight);
            adj_edges[node1-1].push_back(edge(node2-1, weight));
            adj_edges[node2-1].push_back(edge(node1-1, weight));
        }

        scanf("%d", &k);
        for(i=0; i<k; i++) {
            scanf("%d%d%d", &node1, &node2, &weight);
            adj_edges[node1-1].push_back(edge(node2-1, weight));
            adj_edges[node2-1].push_back(edge(node1-1, weight));
        }

        printf("%d\n%d\n", prev_cost, prim());

        for(i=0; i<nodes; i++) adj_edges[i].clear();
    }

    return 0;
}
