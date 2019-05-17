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
using namespace std;
const int N=1005;
int target[N],n;

int main(){
	while(cin>>n&&n){
		while(1){
			cin>>target[1];
			if(target[1]==0)break;
			for(int i=2;i<=n;i++)
			{
				cin>>target[i];
			}
			stack<int> s;
			int A=1,B=1;
			bool ok=true;
			while(B<=n){
				if(target[B]==A){A++;B++;}
				else if(!s.empty()&&s.top()==target[B])
				{
					B++;
					s.pop();
				}
				else if(A<=n)
				{
					s.push(A);
					A++;
				}
				else{
					ok=false;
					break;
				}
			}
			cout<<(ok?"Yes\n":"No\n");
		}
		cout<<endl;
		
	}
}
