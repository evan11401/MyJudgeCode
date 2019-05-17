#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,i;
	string in;
	cin>>n>>in;
	int ans=1;
	char c = in[0];
	for(i=1;i<n;i++){
		if(in[i]!=c)break;
	}
	ans+=i;
	c = in[n-1];
	for(i=n-2;i>=0;i--){
		if(in[i]!=c)break;
	}
	ans+=(n-i-1);
	if(in[0]==in[n-1]){
		ans+=(ans-1-1);
	}
	cout<<ans<<endl;
} 
