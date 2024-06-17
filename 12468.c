#include <stdio.h>

int main ()
{
    int from, to, up, down;

    for ( ; ; ) {
        scanf("%d", &from);
        getchar();
        scanf("%d", &to);
        if (from<0 && to<0) break;

        up=(from>to)? from-to : to-from;
        down=(from>to)? (100-from)+to : (100-to)+from;

        (up>down)? printf("%d\n", down) : printf("%d\n", up);
    }

    return 0;
}
