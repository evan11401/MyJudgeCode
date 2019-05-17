#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
using namespace std;

int main(){
	int n;
	while(cin>>n&&n!=0){
		queue<int> q;
		for(int i=1;i<=n;i++){
			q.push(i);
		}
		vector<int> disc;
		while(q.size()>1){
			int dis = q.front();q.pop();
			int c2 = q.front();q.pop();
			q.push(c2);
			disc.pb(dis);
		}
		cout<<"Discarded cards:";
		bool fir=true;
		for(int i=0;i<n-1;i++){
			if(fir){
				cout<<" "<<disc[i];
				fir=false;
			}else{
				cout<<", "<<disc[i];
			}
		}
		cout<<"\nRemaining card: "<<q.front()<<endl;
	}
}
