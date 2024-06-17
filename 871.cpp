#include <cstdio>
#include <queue>
#include <cstring>

#define white 1
#define gray 2
#define black 3

using namespace std;

char node_content[650];
int row, col, nodes, color[650];

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

int BFS(int start)
{
    int u, i, ones=0;
    queue <int> q;

    color[start]=gray; q.push(start);

    while (!q.empty()) {
        u=q.front(); q.pop();

        for(i=0; i<nodes; i++) {
            if (if_adj(u, i) && node_content[i]=='1') {
                if (color[i]==white) { color[i]=gray; q.push(i); }
            }
        }

        color[u]=black; ones++;
    }

    return ones;
}

int main ()
{
    char prev_ch, present_ch, str[650];
    int i, biggest, b, t, test_case;

    scanf("%d", &test_case);
    getchar(); getchar();

    for(t=0; t<test_case; t++) {
        row=0; i=0; biggest=0; prev_ch='a';

        for ( ; ; ) {
            scanf("%c", &present_ch);
            if (present_ch=='\n' && prev_ch=='\n') break;
            if  (present_ch!='\n') str[i++]=present_ch;
            if  (present_ch=='\n') row++;
            prev_ch=present_ch;
        }
        str[i]='\0';

        nodes=strlen(str); col=nodes/row;

        strcpy(node_content, str);

        for(i=0; i<nodes; i++) color[i]=white;

        for(i=0; i<nodes; i++) {
            if (node_content[i]=='1' && color[i]!=black) {
                b=BFS(i);
                if (b>biggest) biggest=b;
            }
        }

        if (t!=0) printf("\n%d\n", biggest);
        else printf("%d\n", biggest);
    }

    return 0;
}
