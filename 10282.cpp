#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

map <string, string> eng_for;

int main ()
{
    string first, second, word1, word2;
    char ch, demo[30];
    int count=0, i;

    while(1) {
        count++;
        cin>>first>>second;
        if(count!=1) first=ch+first;
        eng_for[first]=second; eng_for[second]=first;
        getchar(); ch=getchar();
        if(ch=='\n') break;
    }

    while(scanf("%s", demo)!=EOF) {
        word1="";
        for(i=0; i<strlen(demo); i++) word1=word1+demo[i];
        word2=eng_for[word1];
        if(word1==eng_for[word2]) cout<<word2<<endl;
        else cout<<"eh"<<endl;
    }

    return 0;
}

