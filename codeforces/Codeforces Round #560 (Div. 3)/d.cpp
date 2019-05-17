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
	int n,nn;
	vector<int> nums;
	cin>>nn;
	while(nn--){
		cin>>n;
		nums.resize(n);
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
			
		sort(nums.begin(),nums.end()); 
		int ans=nums[0]*nums[n-1],i,j;
		for(i=0,j=n-1;i<=j;i++,j--){
			if(ans!= nums[i]*nums[j]){				
				break;
			}
		}		
		if(i<=j){
			cout<<-1<<endl;
			continue;
		}
		for(i=2;i*i<=ans;i++)
		{
			if(ans%i) continue;
			n--;
			if(i*i!=ans) n--;
		}
		
		if(n==0) {
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
} 

