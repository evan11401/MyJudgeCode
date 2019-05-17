#include<iostream>
#include<cstring>
#define int long long 
using namespace std;
const int maxn =65005;
int in;

int getPower(int a,int n,int in){
	if(n==0)return 1;
	else{
		int ret = getPower(a,n/2,in);
		ret = ret*ret;
		ret%=in;
		if(n%2==1)ret*=a;
		ret%=in;
		return ret;
	}
} 
main(){
	int b,p,m;	
	while(cin>>b>>p>>m){		
		cout<<getPower(b,p,m)<<"\n";
	}
}
