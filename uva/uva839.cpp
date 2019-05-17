#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LL long long
const int MAXN = 10000+5;

int flag;
int build(){
	int WL,WR,DL,DR;
	bool b1=true,b2=true;
	cin>>WL>>DL>>WR>>DR;
	if(!WL)WL=build();
	if(!WR)WR=build();
	if(WL*DL!=WR*DR)flag=0;
	return WL+WR;
}
int main(){
	int a;
	cin>>a;
	while(a--){
		flag=1;
		build();
		//cout<<flag<<endl;
		cout<<(flag==1?"YES\n":"NO\n");
		if(a)cout<<endl;
	}
}
