#include <cstdio>
#include <queue>

#define white 1
#define gray 2
#define black 3

using namespace std;

char node_content[10000];
int row, col, nodes, color[10000];

int if_adj(int u, int i)
{
    int row_u, row_i;

    if (i<0 || i>=nodes) return 0;

    if (i==u-col) return 1;
    if (i==u+col) return 1;

    row_u=(u/col)+1; row_i=(i/col)+1;

    if (row_u==row_i) {
        if (i==u+1) return 1;
        if (i==u-1) return 1;
    }

    if (row_u+1==row_i) {
        if (i==u+1+col) return 1;
        if (i==u-1+col) return 1;
    }

    if (row_u-1==row_i) {
        if (i==u+1-col) return 1;
        if (i==u-1-col) return 1;
    }

    return 0;
}

void BFS(int start)
{
    int u, i;
    queue <int> q;

    color[start]=gray;

    q.push(start);

    while (!q.empty()) {
        u=q.front();
        q.pop();

        for(i=0; i<nodes; i++) {
            if (if_adj(u, i) && node_content[i]=='1') {
                if (color[i]==white) { color[i]=gray; q.push(i); }
            }
        }

        color[u]=black;
    }
}

int main ()
{
    int i, count, test_case=1;
    char ch;

    while (scanf("%d", &row)==1) {

        col=row;

        for(i=0; i<10000; i++) node_content[i]='0'; count=0;

        nodes=row*col;

        for(i=0; i<nodes; i++) {
            scanf("%c", &node_content[i]);
            if (node_content[i]=='\n') i=i-1;
        }

        for(i=0; i<nodes; i++) color[i]=white;

        for(i=0; i<nodes; i++) {
            if (node_content[i]=='1' && color[i]!=black) {
                BFS(i);
                count++;
            }
        }

        printf("Image number %d contains %d war eagles.\n", test_case++, count);
    }

    return 0;
}

