/*
ID: evan11401
TASK: zerosum
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

int n,e[9]={1,2,3,4,5,6,7,8,9};
ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");
void dfs(int s,int sum,int num,int sign,string str){
    if(s==n){
        if(sum+sign*num==0){
            fout<<str<<endl;
        }
        return;
    }else{
        dfs(s+1,sum,num*10+e[s],sign,str+" "+(char)(e[s]+'0'));
        dfs(s+1,sum+sign*num,e[s],1,str+"+"+char(e[s]+'0'));
        dfs(s+1,sum+sign*num,e[s],-1,str+"-"+char(e[s]+'0')); 
    }
}

int main (){
    
	fin>>n;
    dfs(1,0,1,1,"1");

	return 0;
}
