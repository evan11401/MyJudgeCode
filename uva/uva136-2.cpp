#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.begin()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
using namespace std;
int main(){
	priority_queue<LL ,vector<LL>, greater<LL> > pq;
	set<LL> s;
	const int cod[3]={2,3,5};
	pq.push(1);
	s.insert(1);
	
	for(int i=1;;i++){
		LL x = pq.top();pq.pop();
		if(i==1500){
			cout<<"The 1500'th ugly number is "<<x<<".\n";
			break;
		}
		for(int i=0;i<3;i++){
			LL x2 = x*cod[i];
			//cout<<x2<<endl;
			if(!s.count(x2)){
				pq.push(x2);
				s.insert(x2);
			}
		}
	}
}
