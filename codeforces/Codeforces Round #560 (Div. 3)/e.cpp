#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y) 
#define int long long
using namespace std;

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,in;
	int mod = 998244353;
	vector<int> a,b; 
	while(cin>>n){
		a.resize(n);b.resize(n);
		for(int i=0;i<n;i++){
			cin>>in;
			a[i] = (i+1)*1ll*(n-i)*in;
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(b.begin(),b.end());
		sort(a.begin(),a.end());
		int ans=0;
		for(int i=0;i<n;i++){
			ans= (ans+((a[i]%mod)*(b[n-1-i]%mod)))%mod;
		}
		cout<<ans<<endl;
	}
} 
