/*
ID: evan11401
TASK: subset
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

long long  dp[40][3000];
int main (){
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int n;
	fin>>n;
    int sum = n*(n+1)/2;
    if(sum&1){
        fout<<0<<endl;
    }else{
        sum>>=1;
        dp[1][0]=dp[1][1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j-i<0){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
                }
            }
        }
        fout<<dp[n][sum]/2<<endl;
    }
    


	return 0;
}
