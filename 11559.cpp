#include <cstdio>
using namespace std;

int main ()
{
    int people, budget, hotels, weeks, i, tariff, j, beds, present_cost;

    while(scanf("%d%d%d%d", &people, &budget, &hotels, &weeks)!=EOF) {
        present_cost=999999;
        for(i=0; i<hotels; i++) {
            scanf("%d", &tariff);
            for(j=0; j<weeks; j++) {
                scanf("%d", &beds);
                if(beds>=people) {
                    if(people*tariff<present_cost) present_cost=people*tariff;
                }
            }
        }
        if(present_cost<=budget) printf("%d\n", present_cost);
        else printf("stay home\n");
    }

    return 0;
}
