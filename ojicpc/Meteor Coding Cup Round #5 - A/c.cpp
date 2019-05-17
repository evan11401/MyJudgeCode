#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int sum=1;
	if(a!=1)sum*=a-1;
	for(int i=a-1;i>0;i--){
		sum*=i;
		cout<<sum<<" "<<i<<endl;
		sum%=b;
	}
	cout<<sum<<endl;
}
