#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct node {
    int seq;
    double cost;
    node(int cons_seq, double cons_cost) {
        seq=cons_seq; cost=cons_cost;
    }
};

struct edge {
    int v;
    double w;
    edge(int cons_v, double cons_w){
        v=cons_v; w=cons_w;
    }
};

bool operator< (node node1, node node2) { return node1.cost>node2.cost; }

int visited[100], nodes_count;
double key[100];
vector <edge> adj_edges[100];

double prim()
{
    int i;
    double total_cost=0;

    for(i=0; i<nodes_count; i++) { key[i]=9999; visited[i]=0; }
    key[0]=0;

    priority_queue <node> PQ; PQ.push(node(0, 0));

    while(!PQ.empty()) {
        node u=PQ.top(); PQ.pop();
        if(visited[u.seq]) continue;

        for(i=0; i<adj_edges[u.seq].size(); i++) {
            edge current_edge=adj_edges[u.seq][i];
            if(visited[current_edge.v]) continue;
            if(key[current_edge.v]>current_edge.w) {
                key[current_edge.v]=current_edge.w;
                PQ.push(node(current_edge.v, key[current_edge.v]));
            }
        }

        visited[u.seq]=1; total_cost=total_cost+u.cost;
    }

    return total_cost;
}

int main ()
{
    int test_case, t, i, j;
    double d, x, y;
    vector <double> node_x, node_y;

    scanf("%d", &test_case);

    for(t=1; t<=test_case; t++) {
        scanf("%d", &nodes_count);

        for(i=0; i<nodes_count; i++) {
            scanf("%lf%lf", &x, &y);
            node_x.push_back(x); node_y.push_back(y);
        }

        for(i=0; i<nodes_count; i++) {
            for(j=0; j<nodes_count; j++) {
                if(j==i) continue;
                d=sqrt(pow(node_x[i]-node_x[j], 2)+pow(node_y[i]-node_y[j], 2));
                adj_edges[i].push_back(edge(j, d));
            }
        }

        if(t!=test_case) printf("%0.2lf\n\n", prim());
        else printf("%0.2lf\n", prim());

        for(i=0; i<nodes_count; i++) adj_edges[i].clear(); node_x.clear(); node_y.clear();
    }

    return 0;
}
