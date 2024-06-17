#include <cstdio>
#include <queue>

#define inf 9999
#define white 1
#define gray 2
#define black 3

using namespace std;

int nodes[64], x_node[64], y_node[64];

int if_adj(int from, int to)
{
    if ((x_node[to]==x_node[from]-2) && (y_node[to]==y_node[from]+1)) return 1;
    if ((x_node[to]==x_node[from]-2) && (y_node[to]==y_node[from]-1)) return 1;

    if ((x_node[to]==x_node[from]+2) && (y_node[to]==y_node[from]+1)) return 1;
    if ((x_node[to]==x_node[from]+2) && (y_node[to]==y_node[from]-1)) return 1;

    if ((y_node[to]==y_node[from]+2) && (x_node[to]==x_node[from]-1)) return 1;
    if ((y_node[to]==y_node[from]+2) && (x_node[to]==x_node[from]+1)) return 1;

    if ((y_node[to]==y_node[from]-2) && (x_node[to]==x_node[from]-1)) return 1;
    if ((y_node[to]==y_node[from]-2) && (x_node[to]==x_node[from]+1)) return 1;

    return 0;
}

int BFS(int src, int dest)
{
    int color[64], d[64], i, u;
    queue <int> q;

    for (i=0; i<64; i++) {
        color[i]=white; d[i]=inf;
    }

    color[src]=gray; d[src]=0;

    q.push(src);

    while (!q.empty()) {
        u=q.front();
        q.pop();

        for(i=0; i<64; i++) {
            if (if_adj(u, i)) {
                if (color[i]==white) { d[i]=d[u]+1; color[i]=gray; q.push(i); }
            }
        }

        color[u]=black;
        if (u==dest) return d[dest];
    }
}

int main ()
{
    int i, j, src, dest, x, y;
    char from[5], to[5];

    for(i=0, j=0; i<8; i++)   { x_node[i]=0; y_node[i]=j++; }
    for(i=8, j=0; i<16; i++)  { x_node[i]=1; y_node[i]=j++; }
    for(i=16, j=0; i<24; i++) { x_node[i]=2; y_node[i]=j++; }
    for(i=24, j=0; i<32; i++) { x_node[i]=3; y_node[i]=j++; }
    for(i=32, j=0; i<40; i++) { x_node[i]=4; y_node[i]=j++; }
    for(i=40, j=0; i<48; i++) { x_node[i]=5; y_node[i]=j++; }
    for(i=48, j=0; i<56; i++) { x_node[i]=6; y_node[i]=j++; }
    for(i=56, j=0; i<64; i++) { x_node[i]=7; y_node[i]=j++; }

    while (scanf("%s%s", from, to)==2) {

        x=from[1]-49; y=from[0]-'a';
        for (i=0; i<64; i++) {
            if (x_node[i]==x && y_node[i]==y) src=i;
        }

        x=to[1]-49; y=to[0]-'a';
        for (i=0; i<64; i++) {
            if (x_node[i]==x && y_node[i]==y) dest=i;
        }

        printf("To get from %s to %s takes %d knight moves.\n", from, to, BFS(src, dest));
    }

    return 0;
}
