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
int scores[MAXN];
int main(){
	int n;
	while(cin>>n){
		memset(scores,0,sizeof(scores));
		for(int i=0;i<n;i++)cin>>scores[i];
		sort(scores,scores+n);
		if(n>=4){
			if(n%4==0 || n%4==1){
				int div = n/4;
				cout<<scores[div-1]<<" "<<scores[2*div-1]<<" "<<scores[3*div-1]<<endl;
			}else if(n%4==2){
				int div = n/4;
				cout<<scores[div-1]<<" "<<scores[2*div-1]<<" "<<scores[3*div]<<endl;
			}
			else if(n%4==3){
				int div = n/4;
				cout<<scores[div-1]<<" "<<scores[2*div]<<" "<<scores[3*div]<<endl;
			}
		}else{
			switch(n){
				case 1:
					cout<<0<<" "<<0<<" "<<scores[0]<<endl;
					break;
				case 2:
					cout<<0<<" "<<scores[0]<<" "<<scores[1]<<endl;
					break;
				case 3:
					cout<<scores[0]<<" "<<scores[1]<<" "<<scores[2]<<endl;
					break;	
			}
		}
	}
}
