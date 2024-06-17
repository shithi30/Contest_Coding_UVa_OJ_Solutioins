#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main ()
{
    int *sequence;
    int *difference;
    int i, j, k, nums, temp;

    while(scanf("%d", &nums)==1) {
        sequence=(int)malloc(nums*sizeof(int));
        for(i=0; i<nums; i++) scanf("%d", &sequence[i]);
        difference=(int)malloc((nums-1)*sizeof(int));
        j=0;
        for(i=0; i<(nums-1); i++) { difference[j]=abs(sequence[i+1]-sequence[i]); j++; }
        for(j=0; j<(nums-1); j++) {
            for(k=j+1; k<(nums-1); k++) {
                if (difference[k]<difference[j]) { temp=difference[k]; difference[k]=difference[j]; difference[j]=temp; }
            }
        }
        for(k=0; k<=(nums-2); k++) {
            if (difference[k]!=(k+1)) break;
        }
        if (k>(nums-2)) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
