#include <stdio.h>

int main ()
{
    double hr, min, hr_angle, min_angle, one_angle, other_angle;

    for( ; ; ) {
        scanf("%lf", &hr);
        getchar();
        scanf("%lf", &min);

        if (hr==0 && min==0) break;
        if(hr==12) hr=0;

        hr_angle=(hr*30)+(0.5*min);
        min_angle=6*min;

        if (hr_angle>min_angle) one_angle=hr_angle-min_angle;
        else one_angle=min_angle-hr_angle;
        other_angle=360-one_angle;

        (one_angle>other_angle)? printf("%0.3lf\n", other_angle) : printf("%0.3lf\n", one_angle);
    }
    return 0;
}
