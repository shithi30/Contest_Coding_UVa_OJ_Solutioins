 #include <stdio.h>
 #include <string.h>
 int main ()
 {
     int test, t, i, c, j;
     char ch, buffer;
     char str[90];
     double sum;

     scanf("%d", &test);
     buffer=getchar();
     for(t=1; t<=test; t++) {
        gets(str);
        sum=0;
        for (i=0; i<strlen(str); i++) {
            if (!(str[i]>='A' && str[i]<='Z')) continue;
            ch=str[i];
            if (!(str[i+1]>='0' && str[i+1]<='9')) {
                if (ch=='C') sum=sum+12.01;
                else if (ch=='H') sum=sum+1.008;
                else if (ch=='O') sum=sum+16.00;
                else if (ch=='N') sum=sum+14.01;
                continue;
            }
            else c=str[i+1]-48;
            if ((i+2)<strlen(str)) {
                if (str[i+2]>='0' && str[i+2]<='9') {
                    c=(10*c)+(str[i+2]-48);
                    if (((i+3)<strlen(str)) && str[i+3]>='0' && str[i+3]<='9') c=(10*c)+(str[i+3]-48);
                }
            }
            for (j=1; j<=c; j++) {
                if (ch=='C') sum=sum+12.01;
                else if (ch=='H') sum=sum+1.008;
                else if (ch=='O') sum=sum+16.00;
                else if (ch=='N') sum=sum+14.01;
            }
        }
        printf("%0.3lf\n", sum);
     }
     return 0;
 }

