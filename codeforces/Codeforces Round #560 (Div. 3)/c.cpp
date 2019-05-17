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
	int n,ansn;
	string in,ans;
	while(cin>>n){
		cin>>in;
		ans="";
		for(int i=0;i<n-1;){
			if(in[i]!=in[i+1]){
				ans+=in[i];
				ans+=in[i+1];
				i+=2;
			}else i++;
		}
		cout<<in.size()-ans.size()<<endl;
		cout<<ans<<endl;
	}
} 

