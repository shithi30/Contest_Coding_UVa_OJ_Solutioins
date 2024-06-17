#include <stdio.h>
#include <string.h>

int main ()
{
    char nums[110][120], nums2[110][120], res[120], res2[120];
    int ind=0, i, zeros, p, carry, sum, j;

    for ( ; ; ) {
        gets(nums[ind]);
        if (nums[ind][0]=='0') break;
        ind++;
    }

    for(i=0; i<ind; i++) {
        zeros=110-strlen(nums[i]);
        p=0;
        for(j=0; j<zeros; j++) nums2[i][p++]='0';
        for(j=0; j<strlen(nums[i]); j++) {
            nums2[i][p++]=nums[i][j];
        }
        nums2[i][p]='\0'; p=0;

    }

    carry=p=0;
    for(j=109; j>=0; j--) {
        sum=0;
        for(i=0; i<ind; i++) {
            sum=sum+(nums2[i][j]-48);
        }
        sum=sum+carry; carry=sum/10;
        res[p]=(sum%10)+48;
        p++;
    }
    res[p]='\0';

    p=0;
    for(i=109; i>=0; i--) {
        res2[p++]=res[i];
    }
    res2[p]='\0';

    for(i=0; i<=109; i++) {
        for(j=0; j<i; j++) {
            if (res2[j]!='0') break;
        }
        if (res2[i]=='0' &&  j==i) continue;
        printf("%c", res2[i]);
    }
    printf("\n");

    return 0;
}
