#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int get_code(char ch)
{
    switch(ch) {
        case 'B' : case 'F' : case 'P' : case 'V' : return 1;
        case 'C' : case 'G' : case 'J' : case 'K' :case 'Q' : case 'S' : case 'X' : case 'Z' : return 2;
        case 'D' : case 'T' : return 3;
        case 'L' : return 4;
        case 'M' : case 'N' : return 5;
        case 'R' : return 6;
        default : return 0;
    }
}

int main ()
{
    char word[30];
    int len, prev_code, present_code, i;

    while(scanf("%s", word)!=EOF) {
        len=strlen(word);
        prev_code=-1;
        for(i=0; i<len; i++) {
            present_code=get_code(word[i]);
            if(present_code!=prev_code && present_code!=0) cout<<present_code;
            prev_code=present_code;
        }
        cout<<endl;
    }

    return 0;
}
