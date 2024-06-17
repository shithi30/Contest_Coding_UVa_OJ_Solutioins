#include <stdio.h>
#include <malloc.h>

int main ()
{
    int mile, juice, test, t, *times, sec, i, msum, jsum;

    scanf("%d", &test);

    for(t=1; t<=test; t++) {

        scanf("%d", &sec);
        times=(int)malloc(sec*sizeof(int));

        msum=jsum=0;

        for(i=0; i<sec; i++) scanf("%d", &times[i]);

        for(i=0; i<sec; i++) {
            mile=(times[i]+1)/30;
            if ((times[i]+1)%30!=0) mile=mile+1;
            msum=msum+(mile*10);
        }

        for(i=0; i<sec; i++) {
            juice=(times[i]+1)/60;
            if ((times[i]+1)%60!=0) juice=juice+1;
            jsum=jsum+(juice*15);
        }

        if (msum>jsum) printf("Case %d: Juice %d\n", t, jsum);
        else if (msum<jsum) printf("Case %d: Mile %d\n", t, msum);
        else printf("Case %d: Mile Juice %d\n", t, msum);
    }

    return 0;
}
