#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	
	int a;
	cin >>a;
	while(a--){
		string aa;
		cin>>aa;
		string bb = aa;
		reverse(aa.begin(),aa.end());
		if(!aa.compare(bb)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
