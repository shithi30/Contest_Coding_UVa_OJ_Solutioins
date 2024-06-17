#include <cmath>
#include <cstdio>
#include <queue>

#define white 1
#define gray 2
#define black 3

using namespace std;

int test=0;

int if_adj(int u, int i)
{
    int diff=i-u, j;

    if (i%diff!=0) return 0;

    if (diff==1) return 0;
    if (diff==2) return 1;

    for(j=2; j<=sqrt(diff); j++) if (diff%j==0) return 0;

    return 1;
}

void BFS(int from, int to)
{
    int color[5000], parent[5000], i, u, count=0, n;
    queue <int> q;

    for(i=1; i<(to+1); i++) { color[i]=white; parent[i]=-1; }
    color[from]=gray;

    q.push(from);

    while (!q.empty()) {

        u=q.front();
        q.pop();

        for(i=2+u; i<(u+u); i++) {
            if (if_adj(u, i)) {
                if (color[i]==white) { parent[i]=u; color[i]=gray; q.push(i); }
            }
        }

        color[u]=black;

        if (u==to) {
            for ( ; ; ) {
                n=parent[u];
                count++;
                if (n==from) break;
                u=n;
            }
            printf("Case %d: %d\n", ++test, count);
            return;
        }
    }

    printf("Case %d: -1\n", ++test);
    return;
}

int main ()
{
    int from, to;

    for ( ; ; ) {
        scanf("%d%d", &from, &to);
        if (from==0 && to==0) break;
        if (from>to) { printf("Case %d: -1\n", ++test); continue; }
        else if (from==to) { printf("Case %d: 0\n", ++test); continue; }
        BFS(from, to);
    }

    return 0;
}
