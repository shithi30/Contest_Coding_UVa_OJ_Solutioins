#include <stdio.h>

int main ()
{
    int sum, num, to_add, k;

    while(scanf("%d%d", &num, &k)==2) {
        sum=num;
        for( ; ; ) {
            to_add=num/k;
            if (to_add==0) break;
            sum=sum+to_add;
            num=to_add+(num%k);
        }
        printf("%d\n", sum);
    }
    return 0;
}
