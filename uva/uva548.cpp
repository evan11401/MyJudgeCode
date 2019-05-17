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
int in_order[MAXN],post_order[MAXN],n,lch[MAXN],rch[MAXN],x;
bool read_list(int *a){
	string line;
	if(!getline(cin,line)) return false;
	stringstream ss(line);
	n=0;
	while(ss>>x) a[n++]=x;
	return n>0;
}
//in_order[L1..R1] post[L2...R2]
int build(int L1,int R1,int L2,int R2){
	if(L1>R1)return 0;
	int root = post_order[R2];
	int p = L1;
	while(in_order[p] !=root)p++;
	int cnt=p-L1;//left T node num
	lch[root] = build(L1,p-1,L2,L2+cnt-1);
	rch[root] = build(p+1,R1,L2+cnt,R2-1);
	return root;
}
int best,best_sum;
void dfs(int u,int sum){
	sum+=u;
	if(!lch[u] && !rch[u]){//leaf
		if(sum < best_sum || (sum==best_sum && u<best)){
			best = u;
			best_sum = sum;
		}
	}
	if(lch[u]) dfs(lch[u],sum);
	if(rch[u]) dfs(rch[u],sum);
}
int main(){
	while(read_list(in_order)){
		read_list(post_order);
		build(0,n-1,0,n-1);
		best_sum = 1000000000;
		dfs(post_order[n-1],0);
		cout<<best<<endl;
	}
}
