#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define int long long
#define PI 2*acos(0)
using namespace std;
int dp[30005];
int coins[5] = {1,5,10,25,50};
main(){
	//ios::sync_with_stdio(0); cin.tie(0);
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<5;i++){
		for(int j=coins[i];j<30005;j++){			
			dp[j]+=dp[j-coins[i]];													
		}
	}
	int n;
	while(cin>>n){
		if(dp[n]==1){
			printf("There is only 1 way to produce %lld cents change.\n",n);
		}else{
			printf("There are %lld ways to produce %lld cents change.\n",dp[n],n);
		}
	}
}

