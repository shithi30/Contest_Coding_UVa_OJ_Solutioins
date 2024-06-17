#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>

#define white 1
#define gray 2
#define black 3

using namespace std;

int graph[1000][1000], path[5000];
char connected_cities[1000][50], cities[1000][50], start_str[50], end_str[50];

void BFS(int start, int end, int nodes, int *path_len)
{
    int color[1000], parent[1000], i, u, p, j;
    queue <int> q;

    for(i=0; i<nodes; i++) { color[i]=white; parent[i]=-1; }

    color[start]=gray;

    q.push(start);

    while (!q.empty()) {
        u=q.front();
        q.pop();

        for(i=0; i<nodes; i++) {
            if (graph[u][i]==1) {
                if (color[i]==white) { parent[i]=u; color[i]=gray; q.push(i); }
            }
        }

        color[u]=black;
        if (u==end) {
            i=0;
            path[i++]=u;
            for( ; ; ) {
                p=parent[u];
                if (p==-1) break;
                path[i++]=p;
                u=p;
            }
            *path_len=i;
            break;
        }
     }
}

int main ()
{
    int connections, input_strings, i, j, city_count, x, y, start, end, path_len, if_two, test_case, t, quaries, q;

    scanf("%d", &test_case);

    for(t=0; t<test_case; t++) {

        scanf("%d%d", &connections, &quaries);

        for(i=0; i<1000; i++) for(j=0; j<1000; j++) graph[i][j]=0;

        input_strings=connections*2;

        for(i=0; i<input_strings; i++) scanf("%s", connected_cities[i]);

        for(i=0, city_count=0; i<input_strings; i++) {
            for(j=0; j<i; j++) if (strcmp(connected_cities[i], connected_cities[j])==0) break;
            if (j==i) strcpy(cities[city_count++], connected_cities[i]);
        }

        for(i=0; i<input_strings; i=i+2) {
            for (j=0; j<city_count ; j++) if (strcmp(connected_cities[i], cities[j])==0) x=j;
            for (j=0; j<city_count ; j++) if (strcmp(connected_cities[i+1], cities[j])==0) y=j;
            graph[x][y]=graph[y][x]=1;
        }

        for(q=0; q<quaries; q++) {
            scanf("%s%s", start_str, end_str);

            for(i=0; i<city_count; i++) if (strcmp(cities[i], start_str)==0) { start=i; break; }
            for(i=0; i<city_count; i++) if (strcmp(cities[i], end_str)==0) { end=i; break; }

            path_len=0;

            for(i=0; i<5000; i++) path[i]=0;

            BFS(start, end, city_count, &path_len);

            for(i=path_len-1; i>=0; i--) printf("%c", cities[path[i]][0]);
            printf("\n");
        }
        if  (t!=test_case-1) printf("\n");
    }

    return 0;
}

