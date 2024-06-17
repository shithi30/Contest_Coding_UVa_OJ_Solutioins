#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int len, i, dist, min_dist, j;
    string str;

    while(1) {
        cin>>len; if(len==0) break;
        cin>>str;

        for(i=0; i<len; i++) {
            if(str[i]=='Z') break;
        }
        if(len!=i) { cout<<"0"<<endl; continue; }

        min_dist=9999999;
        for(i=0; i<len; i++) {
            if(str[i]=='R') {
                for(j=i-1; j>=0; j--) {
                    if(str[j]=='R') break;
                    else if(str[j]=='D') {
                        dist=i-j;
                        if(dist<min_dist) min_dist=dist;
                        break;
                    }
                }
                for(j=i+1; j<len; j++) {
                    if(str[j]=='R') break;
                    else if(str[j]=='D') {
                        dist=j-i;
                        if(dist<min_dist) min_dist=dist;
                        break;
                    }
                }
            }
        }

        cout<<min_dist<<endl;
    }

    return 0;
}
