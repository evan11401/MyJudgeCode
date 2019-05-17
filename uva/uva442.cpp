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
stack<pair<int,int> > s;
int main(){
	int n;
	pair<int,int> alph[30];
	cin>>n;
	char ina;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>ina;
		cin>>x>>y;
		alph[ina-'A'] = mp(x,y);
	}
//	for(int i=0;i<26;i++){
//		cout<<alph[i].first<<" "<<alph[i].second<<endl;
//	}
	string in;
	while(cin>>in){
		while(!s.empty())s.pop();
		int sum=0;
		bool ok=true;
		for(int i=0;i<in.size();i++){
			if(in[i]=='(')continue;
			else if(isalpha(in[i])){
				s.push(alph[in[i]-'A']);
			}
			else if(in[i]==')'){
				int x1=s.top().first;
				int y1 = s.top().second;
				s.pop();
				int x2=s.top().first;
				int y2 = s.top().second;
				s.pop();
//				cout<<x2<<" "<<y2<<endl;
//				cout<<x1<<" "<<y1<<endl;
			
				if(y2!=x1){
					ok=false;
					break;
				}else{
					s.push(mp(x2,y1));
					sum+=x1*y1*x2;
				}
			}
		}
		if(ok)cout<<sum;
		else cout<<"error";
		cout<<endl;
		
	}
}
