#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y) 
using namespace std;


main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string in;
	int n;
	while(cin>>n){
		cin>>in;
		int num=0;
		for(int i=0;i<in.size();i++){
			if(in[i]=='+'){
				num++;
			}else if(num>0){
				num--;
			}
		}
		if(num<0)cout<<0<<endl;
		else cout<<num<<endl;
	}
	
} 
