#include <stdio.h>
int main ()
{

    int d, wall, night, fat;
    double ht, hi, hf, hd, hw, hn, f, day, hd2;

    while (scanf("%d%d%d%d", &wall, &d, &night, &fat)==4) {

        if(wall==0) break;

        hi=0;
        day=1;

        hw=(double)wall;
        hd= (double)d;
        hn=(double)night;
        f=(double)fat;
        hd2=hd*(f/100);

        for( ; ; ) {
            ht=hi+hd;
            hf=ht-hn;
            if (ht>hw) { printf("success on day %0.0lf\n", day); break; }
            else if (hf<0) { printf("failure on day %0.0lf\n", day); break; }
            day++;
            hi=hf;
            hd=hd-hd2;
            if (hd<=0) hd=0;
        }
    }
    return 0;
}
