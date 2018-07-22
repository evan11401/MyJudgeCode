#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cassert >
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.begin()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
using namespace std;
void fill_random_int(vector<int> &v,int cnt){
	v.clear();
	for(int i=0;i<cnt;i++){
		v.push_back(rand());
	}
}
void test_sort(vector<int> &v){
	sort(ALL(v));
	for(int i=0;i<v.size()-1;i++){
		assert(v[i]<=v[i+1]);
	}
}
int main(){
	srand(time(NULL));
	vector<int> v;
	fill_random_int(v,1000000);
	test_sort(v);
	
	
}
