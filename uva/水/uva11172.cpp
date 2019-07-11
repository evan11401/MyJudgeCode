#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define int long long
#define PI 2*acos(0)
using namespace std;

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int nn;
	cin>>nn;
	while(nn--){
		int a,b;
		cin>>a>>b;
		if(a==b)cout<<"=\n";
		else if(a>b)cout<<">\n";
		else cout<<"<\n";
	}
}

