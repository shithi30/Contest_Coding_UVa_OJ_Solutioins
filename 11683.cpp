#include <iostream>
using namespace std;

int main ()
{
    int h, l, heights[10000], i, status, razes, j;

    while(1) {
        cin>>h>>l; if(h==0 && l==0) break;
        for(i=0; i<l; i++) cin>>heights[i];

        razes=0;
        for(i=h; i>=1; i--) {
            status=1;
            for(j=0; j<l; j++) {
                if(i>heights[j]) {
                    if(status==1) { status=0; razes++; }
                }
                else status=1;
            }
        }

        cout<<razes<<endl;
    }

    return 0;
}

