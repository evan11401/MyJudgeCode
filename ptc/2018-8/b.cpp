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
int isAirport[MAXN],airport[MAXN],connected[MAXN][MAXN],railway[MAXN][MAXN];
int main(){
	int nn,n,m,a,b,cost;
	cin>>nn;
	while(nn--){
		memset(isAirport,0,sizeof(isAirport));
		memset(connected,0,sizeof(connected));
		memset(railway,0,sizeof(railway));
		memset(airport,0,sizeof(railway));
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>airport[i];
		for(int i=0;i<m;i++){
			cin>>a>>b>>cost;
			railway[a][b]=cost;railway[b][a]=cost;
		}
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i)continue;
				if(connected[i][j])continue;
				else{
					if(isAirport[i] && isAirport[j])connected[i][j]=1;
					else if(isAirport[i]){
						if(airport[j]<=railway[i][j]){
							sum += airport[j];
							isAirport[j]=1;
							connected[i][j]=1;
							connected[j][i]=1;
						}else{
							sum += railway[i][j];
							connected[i][j]=1;
							connected[j][i]=1;
						}
					}else if(isAirport[j]){
						if(airport[i]<=railway[i][j]){
							sum += airport[i];
							isAirport[i]=1;
							connected[i][j]=1;connected[j][i]=1;
						}else{
							sum += railway[i][j];
							connected[i][j]=1;connected[j][i]=1;
						}
					}else{
						if(airport[i]+airport[j]<=railway[i][j]){
							sum += airport[i];
							sum += airport[j];
							isAirport[i]=1;
							isAirport[j]=1;
							connected[i][j]=1;connected[j][i]=1;
						}else{
							sum += railway[i][j];
							connected[i][j]=1;connected[j][i]=1;
						}
					}
					
				}
				//cout<<i<<" "<<j<<" "<<sum<<endl;
			}
			
		}
		cout<<sum<<endl;
	}
}
