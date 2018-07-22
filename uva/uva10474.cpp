#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
const int maxn=10000;
int main(){
	int num=1,n,q;
	while(cin>>n>>q&&n!=0&&q!=0){
		cout<<"CASE# "<<num++<<":"<<endl;
		int list[maxn]={};
		for(int i=0;i<n;i++)cin>>list[i];
		sort(list,list+n);
		int guess;
		while(q--){
			cin>>guess;
			int ans=lower_bound(list,list+n,guess)-list;
			if(list[ans]==guess)cout<<guess<<" found at "<<ans+1<<endl;
			else cout<<guess<<" not found"<<endl;
		}
	}
}

