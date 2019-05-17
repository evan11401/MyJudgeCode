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
	vector<int> nums;
	int n;
	while(cin>>n){
		nums.resize(n);
		int min_n=1e9+1;
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
		for(int i=1;i<n;i++){
			int minn = min(nums[0],nums[i]);
			minn/=i;
			min_n = min(minn,min_n);
		}
		reverse(nums.begin(),nums.end());
		for(int i=1;i<n;i++){
			int minn = min(nums[0],nums[i]);
			minn/=i;
			min_n = min(minn,min_n);
		}
		cout<<min_n<<endl;
	}
	
	
} 
