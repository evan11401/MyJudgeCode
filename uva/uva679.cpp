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
const int MAXN = 20;
int main(){
	int nn,I,D;
	cin>>nn;
	while(cin>>D&&D!=-1){
		cin>>I;
		
		int k=1,n = (1<<D)-1;
		for(int i=0;i<D-1;i++){
			if(I%2){
				k=k*2;I=(I+1)/2;
			}else{
				k=k*2+1;I/=2;
			}
		}
		cout<<k<<endl;
		
	}
	
}
