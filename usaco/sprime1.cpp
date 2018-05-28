/*
ID: evan11401
TASK: sprime
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int n;
void dfs(int x,int d){
    for(int i=2;i<=x/i;i++)
        if(x%i==0)return;
    if(x==1)return;
    if(d==n){
        printf("%d\n",x);
        return;
    }
    for(int i=(d==0);i<10;i++)
        dfs(x*10+i,d+1);
}
int main(){
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    scanf("%d",&n);
    dfs(0,0);
}
