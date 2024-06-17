#include <iostream>
#include <map>
#include <string>
using namespace std;

int main ()
{
    int s, categories, i, in_category, to_take, j, if_ok, taken;
    string subjects_taken[100], sub;
    map <string, int> subject_category;

    while(1) {
        cin>>s; if(s==0) break; cin>>categories;
        for(i=0; i<s; i++) {
            cin>>subjects_taken[i];
            subject_category[subjects_taken[i]]=-1;
        }

        if_ok=1;
        for(i=0; i<categories; i++) {
            cin>>in_category>>to_take;
            for(j=0; j<in_category; j++) {
                cin>>sub;
                subject_category[sub]=i;
            }
            taken=0;
            for(j=0; j<s; j++) {
                if(subject_category[subjects_taken[j]]==i) taken++;
                subject_category[subjects_taken[j]]=-1;
            }
            if(taken<to_take) if_ok=0;
        }

        if(if_ok==0) cout<<"no"<<endl;
        else cout<<"yes"<<endl;

        subject_category.clear();
    }

    return 0;
}
