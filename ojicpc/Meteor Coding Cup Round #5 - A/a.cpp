#include<iostream>
#include<string>
#include<map>
using namespace std; 
int main(){
	int a,b;
	string in;
	cin>>a;
	map<string,int> desk;
	while(a--){
		cin>>in;
		desk[in]=1;
	}
	cin>>a;
	while(a--){
		cin>>in;
		if(desk[in]==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
