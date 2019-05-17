#include<iostream>
using namespace std;
int main(){
	int nn,l,r;
	cin>>nn;
	while(nn--){
		cin>>l>>r;
		int x=l,y=r;
		int dis = y%x;
		cout<<x<<" "<<y-dis<<endl;
	}
} 
