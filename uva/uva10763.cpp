#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
using namespace std;

int main(){
	int n,a,b;
	while(cin>>n&&n!=0){
		map<int,int> mp;	
		for(int i=0;i<n;i++){
			cin>>a>>b;
			if(a>b){
				a=a+b;
				b=a-b;
				a=a-b;
			}
			if(mp.count(a)){
				mp.erase(a);
			}else{
				mp[a]=b;
			}
		}
		if(mp.size())cout<<"NO\n";
		else cout<<"YES\n";	
		
	}
}
