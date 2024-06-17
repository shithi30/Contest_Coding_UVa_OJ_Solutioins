#include <stdio.h>
int main ()
{
    int c, term1, term2, finl, ct1, ct2, ct3, atten, i;
    double ct, total;

    scanf("%d", &c);
    for (i=1; i<=c; i++) {
        scanf("%d%d%d%d%d%d%d", &term1, &term2, &finl, &atten, &ct1, &ct2, &ct3);
        if(ct1<=ct2 && ct1<=ct3) ct = ((double)(ct2+ct3))/2;
        else if (ct2<=ct3 && ct2<=ct1) ct = ((double)(ct1+ct3))/2;
        else if (ct3<=ct2 && ct3<=ct1) ct = ((double)(ct2+ct1))/2;

        total=term1+term2+finl+ct+atten;

        if (total>=90) printf("Case %d: A\n", i);
        else if (total>=80 && total<90) printf("Case %d: B\n", i);
        else if (total>=70 && total<80) printf("Case %d: C\n", i);
        else if (total>=60 && total<70) printf("Case %d: D\n", i);
        else if (total<60) printf("Case %d: F\n", i);
    }
    return 0;
}
