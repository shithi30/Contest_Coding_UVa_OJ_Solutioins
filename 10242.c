#include <stdio.h>

int main ()
{
    double x1, y1, x2, y2, x3, y3, x4, y4, x, y, ara_x[4], ara_y[4];
    int i, j, avoid1, avoid2, avoid3;

    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &ara_x[0], &ara_y[0], &ara_x[1], &ara_y[1], &ara_x[2], &ara_y[2], &ara_x[3], &ara_y[3])!=EOF) {

        avoid1=avoid2=avoid3=-1;

        for(i=0; i<4; i++) {
            for(j=0; j<i; j++) {
                if(ara_x[i]==ara_x[j] && ara_y[i]==ara_y[j]) {
                    x2=ara_x[i]; y2=ara_y[i];
                    avoid1=i; avoid2=j;
                    break;
                }
            }
        }

        for(i=0; i<4; i++) {
            if(i!=avoid1 && i!=avoid2) {
                x1=ara_x[i]; y1=ara_y[i];
                avoid3=i;
                break;
            }
        }

        for(i=0; i<4; i++) {
            if(i!=avoid1 && i!=avoid2 && i!=avoid3) {
                x3=ara_x[i]; y3=ara_y[i];
                break;
            }
        }

        x=(x1+x3)/2; y=(y1+y3)/2;
        x4=2*x-x2; y4=2*y-y2;

        printf("%0.3lf %0.3lf\n", x4, y4);
    }

    return 0;
}
