#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#define ALL(x) x.begin(),x.begin()
#define INS(x) inserter(x,x.begin())
using namespace std;

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;
int ID(Set x){
	if(IDcache.count(x))return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size()-1;
	
}

int main(){
	
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		stack<int> s;
		for(int i=0;i<m;i++){
			string op;
			cin>>op;
			if(op[0]=='P')s.push(ID(Set()));
			else if(op[0]=='D')s.push(s.top());
			else{
				Set x1 = Setcache[s.top()]; s.pop();
				Set x2 = Setcache[s.top()]; s.pop();
				Set x;
				if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='A'){
					x=x2;
					x.insert(ID(x1));
				}
				s.push(ID(x));
			}
			//cout<<Setcache[s.top()].size()<<endl;
			stack<int> show=s;
			while(!show.empty()){
				cout<<Setcache[show.top()].size()<<" ";
				show.pop();
			}
			cout<<endl;
			
		}
		cout<<"***\n";
	}
}
