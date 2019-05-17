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
using namespace std;
const int MAXN = 100000+5;
int last,cur,nextt[MAXN];
string s; 
int main(){
	while(cin>>s){
		last = cur=0;
		nextt[0]=0;
		s = ' '+s;
		for(int i=1;i<s.length();i++){
			if( s[i]=='[')cur=0;
			else if(s[i]==']')cur=last;
			else{
				nextt[i]=nextt[cur];
				nextt[cur]=i;
				if(cur==last)last=i;
				cur=i;
			}
		}
		for(int i=nextt[0];i!=0;i=nextt[i]){			
			cout<<s[i];
		}
		cout<<endl;
	}
}
