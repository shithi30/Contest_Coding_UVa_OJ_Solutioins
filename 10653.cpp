#include <cstdio>
#include <queue>

#define white 1
#define gray 2
#define black 3
#define inf 9999999

using namespace std;

int graph[1000000], row, col, nodes;
queue <int> adj_u;

void get_adj_u(int u)
{
    int i, row_u, row_i;

    i=u+col; if (i>=0 && i<nodes) adj_u.push(i);
    i=u-col; if (i>=0 && i<nodes) adj_u.push(i);

    row_u=u/col+1;

    i=u+1; row_i=i/col+1; if ((row_u==row_i) && (i>=0 && i<nodes)) adj_u.push(i);
    i=u-1; row_i=i/col+1; if ((row_u==row_i) && (i>=0 && i<nodes)) adj_u.push(i);
}

void BFS(int start, int end)
{
    int color[1000000], u, distance[1000000], i;
    queue <int> q;

    for(i=0; i<nodes; i++) { color[i]=white; distance[i]=inf; }

    color[start]=gray; distance[start]=0; q.push(start);

    while(!q.empty()) {
        u=q.front(); q.pop();

        get_adj_u(u);

        while(!adj_u.empty()) {
            i=adj_u.front(); adj_u.pop();
            if (graph[i]==0) {
                if (color[i]==white) { color[i]=gray; distance[i]=distance[u]+1; q.push(i); }
            }
        }

        color[u]=black;
        if (u==end) { printf("%d\n", distance[u]); break; }
    }
}

int main ()
{
    int bomb_rows, i, bomb_x, bomb_y, bomb_cols, j, start_row, start_col, end_row, end_col, start_node, end_node;

    for ( ; ; ) {
        scanf("%d%d", &row, &col); if(row==0 && col==0) break;

        nodes=row*col;

        for(i=0; i<1000000; i++) graph[i]=0;

        scanf("%d", &bomb_rows);

        for(i=0; i<bomb_rows; i++) {
            scanf("%d", &bomb_x);
            scanf("%d", &bomb_cols);
            for(j=0; j<bomb_cols; j++) { scanf("%d", &bomb_y); graph[bomb_x*col+bomb_y]=1; }
        }

        scanf("%d%d%d%d", &start_row, &start_col, &end_row, &end_col);

        start_node=start_row*col+start_col; end_node=end_row*col+end_col;

        BFS(start_node, end_node);
    }

    return 0;
}
