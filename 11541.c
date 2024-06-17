 #include <stdio.h>
 #include <string.h>
 int main ()
 {
     int test, t, i, c, j;
     char ch, buffer;
     char str[500];
     scanf("%d", &test);
     buffer=getchar();
     for(t=1; t<=test; t++) {
        gets(str);
        printf("Case %d: ", t);
        for (i=0; i<strlen(str); i++) {
            if (!(str[i]>='A' && str[i]<='Z')) continue;
            ch=str[i];
            c=str[i+1]-48;
            if ((i+2)<strlen(str)) {
                if (str[i+2]>='0' && str[i+2]<='9') {
                    c=(10*c)+(str[i+2]-48);
                    if (str[i+3]>='0' && str[i+3]<='9') c=(10*c)+(str[i+3]-48);
                }
            }
            for (j=1; j<=c; j++) printf("%c", ch);
        }
        printf("\n");
     }
     return 0;
 }
