#include <stdio.h>
int main ()
{
    int count, start, end, i, temp, num, s, e;

    while (scanf("%d%d", &s, &e)==2) {
        if (s>e) {start=e; end=s;}
        else {start=s; end=e;}
        for (i=start; i<=end; i++) {
            num=i;
            count=1;
            while (num!=1) {
                if (num%2==0) { num=num/2; count++; }
                else { num=3*num+1; count++; }
            }
            if (i==start) temp=count;
            else if (count>temp) temp=count;
        }
        printf("%d %d %d\n",s, e, temp);
    }
    return 0;
}
