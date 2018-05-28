#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> topoints[205];
int n,e;

bool BFS(int start){
	queue<int> q;
	q.push(start);
	int vistied[205]={};
	
	while(!q.empty()){
		int c = q.front();
		q.pop();
		
		for(int i=0;i<topoints[c].size();i++){
			int nxt = topoints[c][i];
			if(vistied[nxt]==0){
				q.push(nxt);
				if(vistied[c]==1)vistied[nxt]=2;
				else vistied[nxt]=1;
			}
			else if(vistied[c]==vistied[nxt]){
				return false;
			}
		}
	}
	return true;
	
}

int main(){
	while(cin>>n&&n!=0){
		for(int i=0;i<205;i++){
			topoints[i].clear();
		}
		cin>>e;
		int a,b;
		for(int i=0;i<e;i++){			
			cin>>a>>b;
			topoints[a].push_back(b);
			topoints[b].push_back(a);
		}	
		cout<<(BFS(a)?"BICOLORABLE." : "NOT BICOLORABLE.")<<endl;
	}
}
