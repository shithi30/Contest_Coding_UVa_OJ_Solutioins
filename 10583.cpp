#include <cstdio>
#include <vector>

using namespace std;

int n, m, believers_religions[50000], religions[50000];

int get_religion(int believer)
{
    int i;
    vector <int> v;

    for ( ; ; ) {
        if(believers_religions[believer]==believer) break;
        v.push_back(believer);
        believer=believers_religions[believer];
    }
    for(i=0; i<v.size(); i++) believers_religions[v[i]]=believer;

    return believer;
}

void shift_religion(int from, int to)
{
    int i, religion_to, religion_from;

    religion_to=get_religion(to); religion_from=get_religion(from);

    if(religion_to==religion_from) return;

    for(i=0; i<n; i++) {
        if(believers_religions[i]==religion_from) believers_religions[i]=religion_to;
    }
}

int main ()
{
    int i, student1, student2, count_religions, test_case=1;

    for( ; ; ) {
        scanf("%d%d", &n, &m); if(n==0 && m==0) break;

        count_religions=0; for(i=0; i<n; i++) believers_religions[i]=i;

        for(i=0; i<m; i++) {
            scanf("%d%d", &student1, &student2);
            shift_religion(student1-1, student2-1);
        }

        for(i=0; i<n; i++) religions[believers_religions[i]]=1;
        for(i=0; i<n; i++) if(religions[i]==1) count_religions++;
        printf("Case %d: %d\n", test_case++, count_religions);

        for(i=0; i<n; i++) believers_religions[i]=religions[i]=0;
    }

    return 0;
}
