#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>

#define white 1
#define gray 2
#define black 3

using namespace std;

vector <string> length_words[15];

int find_word_index(string word, int l, int s)
{
    int i;

    for(i=0; i<s; i++) {
        if(length_words[l][i]==word) return i;
    }
}

int if_adj_word(string word1, string word2, int l)
{
    int i, diff=0;

    for(i=0; i<l; i++) {
        if(word1[i]!=word2[i]) diff++;
    }

    if(diff==1) return 1;
    return 0;
}

int BFS_count_steps(string src, string dest, int l)
{
    int u, v, i, nodes, src_index, dest_index, color[250], dist[250]; queue <int> q;

    nodes=length_words[l].size(); src_index=find_word_index(src, l, nodes); dest_index=find_word_index(dest, l, nodes);

    for(i=0; i<nodes; i++) { color[i]=white; dist[i]=9999; }
    color[src_index]=gray; dist[src_index]=0;
    q.push(src_index);

    while(!q.empty()) {
        u=q.front(); q.pop();

        for(v=0; v<nodes; v++) {
            if(if_adj_word(length_words[l][u], length_words[l][v], l)) {
                if(color[v]==white) {
                    color[v]=gray; dist[v]=dist[u]+1; q.push(v);
                }
            }
        }

        color[u]=black;
        if(u==dest_index) return dist[u];
    }
}

int main ()
{
    int steps, tests, t, i;
    string word, src, dest, attach;
    char ch1, ch2;

    cin>>tests;
    for(t=1; t<=tests; t++) {
        if(t!=1) cout<<endl; for(i=0; i<15; i++) length_words[i].clear(); attach="";

        while(1) {
            cin>>word;
            if(word=="*") break;
            length_words[word.length()].push_back(word);
        }

        while(1) {
            cin>>src>>dest;
            src=attach+src;

            steps=BFS_count_steps(src, dest, src.length());
            cout<<src<<" "<<dest<<" "<<steps<<endl;

            ch1=getchar(); ch2=getchar();
            if(ch1=='\n' && ch2=='\n') break;
            else if(ch1=='\n' && ch2==EOF) break;
            else if(ch1==EOF) break;
            else attach=ch2;
        }
    }

    return 0;
}

