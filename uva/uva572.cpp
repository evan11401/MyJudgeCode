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
const int MAXN = 100+5;
int m,n,went[MAXN][MAXN];
string mapp[MAXN];
void dfs(int r,int c,int id){
	if(r<0 || r>=m || c<0 || c>=n)return;
	if(went[r][c]>0 || mapp[r][c]!='@')return;
	went[r][c]=id;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if(i!=0 || j!=0)dfs(r+i,c+j,id);
}

int main(){
	while(cin>>m>>n&&m!=0){
		int cnt =0;
		memset(went,0,sizeof(went));
		for(int i=0;i<m;i++){
			cin>>mapp[i];
		}		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(went[i][j]==0 && mapp[i][j]=='@')dfs(i,j,++cnt);
			}
		}
		cout<<cnt<<endl;
	}
}
