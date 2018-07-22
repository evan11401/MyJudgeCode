#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.begin()
#define INS(x) inserter(x,x.begin())
using namespace std;
int main(){
	int n,nn=1;
	const int maxn = 1005;
	while(cin>>n&&n!=0){
		map<int,int> teams;
		int team_n,team_num=0,num;
		while(n--){
			cin>>team_n;
			while(team_n--){
				cin>>num;
				teams[num]=team_num;
			}
			team_num++;
		} 
		string command;
		queue<int> q,qs[maxn];
		cout<<"Scenario #"<<nn++<<endl;
		while(cin>>command&&command[0]!='S'){
			if(command[0]=='E'){
				int in;
				cin>>in;
				int team_n=teams[in];
				if(qs[team_n].empty())q.push(team_n);
				qs[team_n].push(in);
			}
			else if(command[0]=='D'){
				int frtq = q.front();
				cout<<qs[frtq].front()<<endl;
				qs[frtq].pop();
				if(qs[frtq].empty())q.pop();
			}
		}
		cout<<endl;
	}
}
