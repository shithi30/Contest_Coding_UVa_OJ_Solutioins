#include <stdio.h>
int main ()
{
    int res, count, need, test=0;
    while (scanf("%d", &need)==1) {
        ++test; res=1, count=0;
        if (need<0) break;
        else if(need==1 || need==0) { printf("Case %d: 0\n", test); }
        else for ( ; ; ) {
            res=res*2;
            count=count+1;
            if (res>=need) { printf("Case %d: %d\n", test, count); break; }
        }
    }
    return 0;
}
