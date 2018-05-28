#include<iostream>
using namespace std;
int main(){
	int vt,vo;
	while(cin>>vt>>vo){
		if(vt==0&&vo==0){
			break;
		}
		int r = vt%(2*vo);
		if(r==vo){
			cout<<0<<endl;
		}else if(r<vo){
			cout<<vt/(2*vo)<<endl;
		}else{
			cout<<vt/(2*vo)+1<<endl;
		}
	}
}
