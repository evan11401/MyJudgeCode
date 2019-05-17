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
const int 	N=1005;
deque<int> qr;
queue<int> qb;
vector<string> prg[N];
string s;
int flag=0;
int t[N],p[N],var[26],lim;
void run(int i){
	int rt = lim,v;
	string cur;
	while(rt>0){
		cur = prg[i][p[i]];
		if(cur[2]== '='){
			rt-=t[0];
			v = cur[4]-'0';
			if(cur.size()==6)v=v*10+cur[5]-'0';
			var[cur[0]-'a']=v;
		}else if(cur[2]=='i'){
			rt-=t[1];
			cout<<i+1<<": "<<var[cur[6]-'a']<<endl;
		}else if(cur[2]=='c'){
			rt-=t[2];
			if(flag){
				qb.push(i);
				return;
			}
			else flag = 1;
		}else if(cur[2]=='l'){
			flag = 0;
			rt-=t[3];
			if(!qb.empty()){
				v = qb.front();
				qb.pop();
				qr.push_front(v);
			}
		}else return;
		p[i]++;
	}
	qr.push_back(i);
}
int main(){
	int nn,n;
	
	cin>>nn;
	while(nn--){
		cin>>n;
		for(int i=0;i<5;i++)cin>>t[i];
		cin>>lim;
		for(int i=0;i<n;i++){
			prg[i].clear();
			while(getline(cin,s)){
				if(s == "") continue;
				prg[i].push_back(s);
				if(prg[i].back() == "end") break;
			}
			qr.push_back(i);
		}
		memset(p, 0, sizeof(p));
    	memset(var, 0, sizeof(var));
    	while(!qr.empty()){
    		int cur =qr.front();
    		qr.pop_front();
    		run(cur);
		}
		if (nn)cout<<endl;
	}
}
