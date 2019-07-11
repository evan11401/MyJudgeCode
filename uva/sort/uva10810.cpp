#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define int long long
#define PI 2*acos(0)
using namespace std;
vector<int> nums,buffer;
int ans;
void merge(int l,int mid,int r){
	int lcnt=l,rcnt=mid+1,bufcnt=0;
	while(lcnt<=mid && rcnt<=r){
		if(nums[rcnt]<nums[lcnt]){
			buffer[bufcnt++] = nums[rcnt++];
			ans+=(mid-lcnt+1);
		}else{
			buffer[bufcnt++] = nums[lcnt++];
		}
	}
	while(lcnt<=mid)buffer[bufcnt++] = nums[lcnt++];
	while(rcnt<=r)buffer[bufcnt++] = nums[rcnt++];
	for(bufcnt=0;l<=r;l++)
		nums[l] = buffer[bufcnt++];
}
void mergeSort(int l,int r){
	if(l==r)return;
	int mid = (l+r)/2;
	
	mergeSort(mid+1,r);
	mergeSort(l,mid);
	merge(l,mid,r);
}

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	buffer.resize(500005);
	while(cin>>n&&n!=0){
		nums.resize(n);
		ans=0;
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
		mergeSort(0,n-1);
		cout<<ans<<endl;
	}
}

