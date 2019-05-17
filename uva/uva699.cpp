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
int sum[MAXN];

void build(int p){
	int in;
	cin>>in;
	if(in==-1)return;
	sum[p]+=in;
	build(p-1);
	build(p+1);
}
int main(){
	int a,kase=1;
	
	while(cin>>a&&a!=-1){
		memset(sum,0,sizeof(sum));
		int p=MAXN/2;
		sum[p]=a;
		build(p-1);
		build(p+1);
		while(sum[p]!=0)p--;
		cout<<"Case "<<kase++<<":\n";
		cout<<sum[++p];
		p++;
		while(sum[p]!=0){
			cout<<" "<<sum[p++];
		}
		cout<<"\n\n";
		
	}
}
