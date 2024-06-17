#include <cstdio>
#include <queue>
#include <cstring>

#define white 1
#define gray 2
#define black 3

using namespace std;

char maze[30][80];
int color[30][80], longest, lines;
queue <int> q;

void get_adj(int start_x, int start_y)
{
    int x, y;

    x=start_x; y=start_y-1; if(start_y>=0 && start_y<longest) { q.push(x); q.push(y); }
    x=start_x; y=start_y+1; if(start_y>=0 && start_y<longest) { q.push(x); q.push(y); }
    y=start_y; x=start_x-1; if(start_x>=0 && start_x<lines) { q.push(x); q.push(y); }
    y=start_y; x=start_x+1; if(start_x>=0 && start_x<lines) { q.push(x); q.push(y); }
}

void DFS_visit(int start_x, int start_y)
{
    int x, y;

    color[start_x][start_y]=gray;

    get_adj(start_x, start_y);

    while(!q.empty()) {
        x=q.front(); q.pop();
        y=q.front(); q.pop();

        if (color[x][y]==white && maze[x][y]==' ') DFS_visit(x, y);
    }

    color[start_x][start_y]=black;
    maze[start_x][start_y]='#';
}

void DFS(int start_x, int start_y)
{
    int i, j;

    for(i=0; i<30; i++) for(j=0; j<80; j++) color[i][j]=white;

    DFS_visit(start_x, start_y);
}

int main ()
{
    int test_case, t, i, j, len, start_x, start_y;
    char line[80];

    scanf("%d", &test_case); getchar();

    for(t=0; t<test_case; t++) {
        for(i=0; gets(line);  ) {
            strcpy(maze[i], line);
            len=strlen(line);
            for(j=0; j<len; j++) if(maze[i][j]!='_') break;
            i++;
            if (j==len) break;
        }

        lines=i;

        for(i=0; i<lines; i++) {
            len=strlen(maze[i]);
            for(j=0; j<len; j++) {
                if(maze[i][j]=='*') { start_x=i; start_y=j; }
            }
        }

        for(i=0, longest=-1; i<lines; i++) {
            len=strlen(maze[i]);
            if(len>longest) longest=len;
        }

        DFS(start_x, start_y);

        for(i=0; i<lines; i++) printf("%s\n", maze[i]);
    }

    return 0;
}
