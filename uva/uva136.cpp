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
using namespace std;
int main(){
	int ug_num[1600]={};
	ug_num[0]=1;
	int n2=0,n3=0,n5=0;
	for(int i=1;i<1500;i++){
		for(;n2<i;n2++){
			if(ug_num[n2]*2 > ug_num[i-1])break;
		}
		for(;n3<i;n3++){
			if(ug_num[n3]*3 > ug_num[i-1])break;
		}
		for(;n5<i;n5++){
			if(ug_num[n5]*5 > ug_num[i-1])break;
		}
		cout<<ug_num[n2]*2<<" "<<ug_num[n3]*3<<" "<<ug_num[n5]*5<<endl;
		ug_num[i] = min(ug_num[n2]*2, min(ug_num[n3]*3,ug_num[n5]*5));
	}
	cout<<ug_num[1499]<<endl;
}
