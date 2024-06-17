#include <stdio.h>


int main ()
{
    int num_of_friends, i, j, k, to_spend, to_give_to, div, balance[200], t=0;
    char friends[200][200], name[100], friend_now[100];


    while (scanf("%d", &num_of_friends)==1) {

        t++; if (t!=1) printf("\n");

        for(i=0; i<200; i++) balance[i]=0;

        for (i=0; i<num_of_friends; i++) scanf("%s", friends[i]);

        for (k=0; k<num_of_friends; k++) {
            fflush(stdin);

            scanf("%s", name);
            scanf("%d", &to_spend);
            scanf("%d", &to_give_to);

            if (to_spend==0 || to_give_to==0) continue;

            div=to_spend/to_give_to;

            for(i=0; i<num_of_friends; i++) {
                if (strcmp(name, friends[i])==0) {
                    balance[i]=balance[i]-to_spend+(to_spend%to_give_to);
                    break;
                }
            }

            for (j=0; j<to_give_to; j++) {
                scanf("%s", friend_now);
                for (i=0; i<num_of_friends; i++) {
                    if (strcmp(friend_now, friends[i])==0) {
                        balance[i]=balance[i]+div;
                        break;
                    }
                }
            }

        }

        for(i=0; i<num_of_friends; i++) { printf("%s %d\n", friends[i], balance[i]); }
        fflush(stdin);
    }

    return 0;
}

