/*
ID: evan11401
TASK: holstein
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int vim_need[50];
int feeds[50][50];
int now[50];
int vnow[50];
int ans[50];
int v,g;
int cnt = 0x3f3f3f3f;
bool check()  
{  
    for(int i = 0; i < v; i++)  
    {  
        if(now[i] < vim_need[i]) return false;  
    }  
    return true;  
}  
void dfs(int deep,int num){
    if(deep==g)return;

    for(int i=0;i<v;i++){
        now[i]+=feeds[deep][i];
    }
    vnow[num] = deep;
    if(check()){
        if(num<cnt){
            cnt = num;
            for(int i=1;i<=num;i++){
                ans[i] = vnow[i];
            }
        }
    }else{
        dfs(deep+1,num+1);
    }
    for(int i=0;i<v;i++){
        now[i]-=feeds[deep][i];
    }
    dfs(deep+1,num);

}
int main (){
	ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
	fin >>v;
    for(int i=0;i<v;i++)
        fin>>vim_need[i];
    fin >>g;
    for(int i=0;i<g;i++){
        for(int j=0;j<v;j++){
            fin >> feeds[i][j];
        }
    }
    dfs(0,1);
    fout<<cnt;
    for(int i=1;i<=cnt;i++)
        fout<<" "<<ans[i]+1;
    fout <<endl;
    
	return 0;
}
