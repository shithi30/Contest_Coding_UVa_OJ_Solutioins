#include <stdio.h>

int main ()
{
    int i, people, budget, hotels, weekends, tariff, flag, j, beds, cost;

    while (scanf("%d%d%d%d", &people, &budget, &hotels, &weekends)==4) {
        flag=0;
        for(i=1; i<=hotels; i++) {
            scanf("%d", &tariff);
            for(j=1; j<=weekends; j++) {
                scanf("%d", &beds);
                if ((beds>=people)&&flag==0) { cost=tariff*people; flag=1; break; }
                else if ((beds>=people)&&(flag==1)) { if((tariff*people)<cost) cost=tariff*people; break; }
            }
        }
        if (cost<=budget) printf("%d\n", cost);
        else printf("stay home\n");
    }
    return 0;
}
