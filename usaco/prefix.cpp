/*
ID: evan11401
TASK: prefix
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <cstring>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

struct trie_node{
    trie_node* next[26];
    bool is_termital;
    trie_node(){
        memset(next,0,sizeof(next));
        is_termital = false;
    }
};

void insert_node(trie_node* root ,string str, int len){
    trie_node* cur = root;
    for(int i=0;i<len;i++){
        if(cur->next[str[i]-'A']==NULL){
            cur->next[str[i]-'A'] = new trie_node;
        }
        cur = cur->next[str[i]-'A'];
    }
    cur->is_termital = true;
}

bool find_str(trie_node* root, string str,int len,int end){
    trie_node * cur = root;
    for(int i=len;i<len+end;i++){
        if(cur->next[str[i]-'A']==NULL)
            return false;
        else
            cur = cur->next[str[i]-'A'];
    }
    if(cur->is_termital)
        return true;
    else
        return false;
}

string buf;
int dp[2000001];
int buf_len;
trie_node root;

int main (){
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    while(true){
        string l;
        fin>>l;
        if(l==".")break;
        insert_node(&root, l,l.size());
    }
    while(fin.good()){
        string l;
        fin>>l;
        buf+=l;
    }
    //fin>>buf;
    buf_len = buf.size();
    dp[buf_len]=0;
    for(int i=buf_len-1;i>=0;--i){
       for(int j=1;j<=10&&i+j-1<buf_len;++j){
           //fout<<i<<" "<<j<<endl; 
           for(int a=i;a<i+j;a++){
               //fout<<buf[a];
           }
           //fout<<endl;
           if(find_str(&root,buf,i,j)){
                //fout<<"finded"<<endl;
               if(dp[i+j]+j>dp[i])
                   dp[i] = dp[i+j]+j;
                /*for(int a=0;a<buf_len;a++)
                    fout<<dp[a]<<" ";*/
                //fout<<endl;
           }       
       }
    }
    fout<<dp[0]<<endl;

	return 0;
}
