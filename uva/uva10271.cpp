#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[1050][5005];
int a[5005];
int n,k;
int main(){
	int N;
	cin>>N;
	while(N--){
		cin>>k>>n;
		k+=8;
		for(int i=n;i>0;i--){
			cin>>a[i];
		}
		
		memset(dp,INF,sizeof(dp));
		
		for(int i=0;i<=n;i++){
			dp[0][i]=0;
		}
		
		for(int i = 1; i <= k; i++) { 
			for(int j = i*3; j <= n; j++) { 
				dp[i][j] = min(dp[i][j-1],dp[i-1][j-2] + (a[j]-a[j-1]) * (a[j]-a[j-1]));
			}
		}
		
		cout<<dp[k][n]<<endl;
	}
}
