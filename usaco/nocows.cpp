/*
ID: evan11401
TASK: nocows
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

ll dp[201][100];
ll n,k;

void dyp(){
    for(int j=1;j<=k;j++)
        for(int i=1;i<=n;i+=2)
            for(int kk=1;kk<=i-2;kk++)
                dp[i][j] = (dp[i][j]+(dp[kk][j-1]*dp[i-kk-1][j-1]))%9901;

}

int main (){
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
	fin>>n>>k;
    for(int i=1;i<=k;i++)
        dp[1][i]=1;
    dyp();
    fout<<(dp[n][k]+9901-dp[n][k-1])%9901<<endl;

	return 0;
}
