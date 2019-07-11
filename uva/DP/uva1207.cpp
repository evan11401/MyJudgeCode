#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y) 
#define int long long
using namespace std;
/*
	using Edit Distance
	insert dp[i][j-1]+1
	deletion dp[i-1][j]+1
	mismatch dp[i-1][j-1]+1
	match dp[i-1][j-1]

*/
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a,b;
	string aa,bb;
	vector<vector<int> > dp;
	while(cin>>a>>aa){
		cin>>b>>bb;
		dp.resize(a+1);
		for(int i=0;i<a+1;i++){
			dp[i].resize(b+1);
			dp[i][0]=i;
		}
		for(int i=0;i<b+1;i++){
			dp[0][i]=i;
		}
		
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				if(aa[i-1]==bb[j-1]){
					dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j-1],dp[i-1][j]+1));
				}else{
					dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j-1]+1,dp[i-1][j]+1));
				}
			}
		}
		cout<<dp[a][b]<<endl;
	}
} 
