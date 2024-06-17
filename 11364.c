#include <stdio.h>
#include <malloc.h>

int main ()
{
    int test, shops, t, temp, i, j, sum;
    int *shop_nos;

    scanf("%d", &test);

    for (t=1; t<=test; t++) {

        scanf("%d", &shops);
        sum=0;
        shop_nos=(int)malloc(shops*sizeof(int));

        for(i=0; i<shops; i++) scanf("%d", &shop_nos[i]);

        for (i=0; i<shops; i++) {
            for (j=i+1; j<shops; j++) {
                if (shop_nos[j]<shop_nos[i]) {
                    temp=shop_nos[j];
                    shop_nos[j]=shop_nos[i];
                    shop_nos[i]=temp;
                }
            }
        }

        for (i=0; i<(shops-1); i++) sum=sum+(shop_nos[i+1]-shop_nos[i]);
        printf("%d\n", 2*sum);
        free(shop_nos);
    }
    return 0;
}
