#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define int long long
using namespace std;
/*
	using disjoint set
	increacing finding the edge
	if edge[v1]==edge[v2] there is a cycle
	else setunion(v1,v2)
*/
int node[1001];
int V,E;
int a,b,c;
void setunion(int x,int y){
	if(node[x]!=node[y]){
		int gmin = min(node[x],node[y]);
		int gmax = max(node[x],node[y]);
		for(int i=0;i<V;i++){
			if(node[i]==gmax){
				node[i]=gmin;
			}
		}
	}
}
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int> ans;
	priority_queue<pair<int, pair<int,int> > > q; 
	while(cin>>V>>E){
		if(V==0&&E==0)break;
		ans.clear();
		for(int i=0;i<V;i++){
			node[i]=i;
		}
		for(int i=0;i<E;i++){
			cin>>a>>b>>c;
			q.push(mp((-c),mp(a,b)));
		}
		for(int i=0;i<E;i++){		
			int v1 = q.top().second.first;
			int v2 = q.top().second.second;
			int w = q.top().first;
			if(node[v1]==node[v2]){
				ans.pb(-w);
			}else{
				setunion(v1,v2);
			}
			q.pop();
		}		
		if(ans.size()==0){
			cout<<"forest\n";
		} else{
			for(int i=0;i<ans.size();i++){
				if(i!=0)cout<<" ";
				cout<<ans[i];
			}
			cout<<endl;
		}
		while(!q.empty())
			q.pop();
	} 
}
