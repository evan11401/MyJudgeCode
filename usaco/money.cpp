/*
ID: evan11401
TASK: money
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
#define  ll long long 
using namespace std;

int main (){
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    int v,n;
    int coin[30]={};
    ll res[10005][30]={};
	fin>>v>>n;
    for(int i=0;i<v;i++)
        fin>>coin[i];
    int tmp = coin[0];  
    while(tmp <= n) {  
        res[tmp][1] = 1;  
        tmp += coin[0];  
    }
    for(int i = 1; i <= v; i++)  
        res[0][i] = 1;  

    for(int i = 2; i <= v; i++) {  
        for(int j = 1; j <= n; j++) {  
            if(j - coin[i-1] >= 0)  
                res[j][i] = res[j-coin[i-1]][i] + res[j][i-1];  
            else  
                res[j][i] = res[j][i-1];  
        }  
    }  
    fout<<res[n][v]<<endl;
	return 0;
}
