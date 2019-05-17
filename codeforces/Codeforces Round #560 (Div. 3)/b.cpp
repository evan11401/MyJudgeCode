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
	int n;
	vector<int> nums;
	while(cin>>n){
		nums.resize(n);
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
		sort(nums.begin(),nums.end()); 
		int ans=0,j,i;
		for(i=0,j=1;i<n;i++){
			//cout<<nums[i]<<" "<<j<<endl;
			if(nums[i] >= j){
				j++;
				ans++;
			}
			//cout<<j<<endl;
		}
		cout<<ans<<endl;
	}
} 
