#include <stdio.h>

int main ()
{
    int now_have, consume, newly_got;

    while(scanf("%d", &now_have)!=EOF) {
        consume=now_have;

        while(1) {
            newly_got=now_have/3;
            now_have=newly_got+(now_have%3);
            consume=consume+newly_got;
            if(now_have==2) { consume++; break; }
            else if(now_have==1) break;
        }

        printf("%d\n", consume);
    }

    return 0;
}
