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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LL long long
using namespace std;
const int MAXN = 100000+5;
int rright[MAXN],lleft[MAXN];
void link(int L,int R){
	rright[L]=R;
	lleft[R]=L;
}
int n,num=1;
int main(){
	 int m;
	 while(cin>>n>>m){
	 	for(int i=1;i<=n;i++){
	 		lleft[i]=i-1;
	 		rright[i]=(i+1)%(n+1);
		}
		rright[0]=1;lleft[0]=n;
		int op,X,Y,inv=0;
		
		while(m--){
//			int c=0;
//			for(int i=1;i<=n;i++){
//				c = rright[c];
//				cout<<c<<" ";
//			}
//			cout<<endl;
			
			cin>>op;
			if(op==4)inv = !inv;
			else{
				cin>>X>>Y;
				if(op==3 && rright[Y] == X) swap(X,Y);
				if(op!=3 && inv) op = 3-op;
				if(op == 1 && X==lleft[Y])continue;
				if(op == 2 && X == rright[Y])continue;
				
				int LX = lleft[X],RX = rright[X],LY = lleft[Y],RY = rright[Y];
				if(op == 1){
					link(LX,RX);link(LY,X);link(X,Y);
				}
				else if(op==2){
					link(LX,RX);link(Y,X);link(X,RY);
				}
				else if(op==3){
					if(rright[X]==Y){
						link(LX,Y);link(Y,X);link(X,RY);
					}else{
						link(LX,Y);link(Y,RX);link(LY,X);link(X,RY);
					}
				}
			}
			
		}
		int b=0;
		LL ans=0;
		for(int i=1;i<=n;i++){
			b = rright[b];
			if(i%2==1)ans+=b;
		}
		if(inv && n%2==0)ans = (LL)n*(n+1)/2 - ans;
		cout<<"Case "<<num++<<": "<<ans<<endl; 
		
	 }
}
