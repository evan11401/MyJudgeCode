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
/*
0˙程╄笷禯瞒琌0
1˙程╄笷禯瞒琌1(1)
2˙程╄笷禯瞒琌2(1 1)
3˙程╄笷禯瞒琌4(1 2 1)
4˙程╄笷禯瞒琌6(1 2 2 1)
5˙程╄笷禯瞒琌9(1 2 3 2 1)
6˙程╄笷禯瞒琌12(1 2 3 3 2 1)
*/
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int nn,a,b,dis;
	cin>>nn;
	while(nn--){
		cin>>a>>b;
		dis = b-a;
		if(dis==0){
			cout<<"0\n";
			continue;
		}
		int sq = (int)sqrt(dis);
		int ans;
		if(sq*sq==dis)ans = sq*2-1;
		else if(sq*sq+sq<dis) ans = sq*2+1;
		else ans = sq*2;
		cout<<ans<<endl;
	}
}

