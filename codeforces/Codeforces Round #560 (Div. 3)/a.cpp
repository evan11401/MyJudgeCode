#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y) 
using namespace std;

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,x,y,i;
	string num;
	while(cin>>n>>x>>y){
		cin>>num;
		int ans=0;
		//reverse(num.begin(),num.end());
		//cout<<x<<y<<endl;
		for(i=n-x;i<n;i++){
			if(i==n-y-1){			
				if(num[i]!='1')ans++;
			}else{			
				if(num[i]!='0')ans++;
			}
			//cout<<i<<" "<<num[i]<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
} 
