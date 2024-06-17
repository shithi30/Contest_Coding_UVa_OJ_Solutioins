#include <stdio.h>
#include <malloc.h>

int main ()
{
    int test, t, i, j, k, swaps, ind, temp, nums, count;
    int *sorted, *ara;

    scanf("%d", &test);

    for (t=1; t<=test; t++) {

        scanf("%d", &nums);
        ara=(int)malloc(nums*sizeof(int));
        sorted=(int)malloc(nums*sizeof(int));

        for(i=0; i<nums; i++) { scanf("%d", &ara[i]); sorted[i]=ara[i]; }

        for(i=0; i<(nums-1); i++) {
            for (j=i+1; j<nums; j++) {
                if (sorted[j]<sorted[i]) {
                    temp=sorted[j];
                    sorted[j]=sorted[i];
                    sorted[i]=temp;
                }
            }
        }

        count=0;

        for(i=0; i<nums; i++) {
            for(j=i; j<nums; j++) {
                if(sorted[i]==ara[j]) { ind=j; break; }
            }
            swaps=ind-i;
            for(k=1; k<=swaps; k++) {
                temp=ara[ind];
                ara[ind]=ara[ind-1];
                ara[ind-1]=temp;
                count++;
                ind--;
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
        free(ara); free(sorted);
    }
    return 0;
}

