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
0�B�̦h���F���Z���O0
1�B�̦h���F���Z���O1(1)
2�B�̦h���F���Z���O2(1 1)
3�B�̦h���F���Z���O4(1 2 1)
4�B�̦h���F���Z���O6(1 2 2 1)
5�B�̦h���F���Z���O9(1 2 3 2 1)
6�B�̦h���F���Z���O12(1 2 3 3 2 1)
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

