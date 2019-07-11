#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define int long long
#define PI 2*acos(0)
using namespace std;

/*
sorting in O(n)
*/

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a[105];
	int n,in;
	while(cin>>n&&n!=0){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			cin>>in;
			a[in]++;
		}
		int count=0;
		for(int i=0;i<105;i++){
			if(a[i]!=0){
				while(a[i]--){
					cout<<i;
					if(count!=n-1)cout<<" ";
					count++;
				}				
			}
		}
		cout<<endl;
	}
}

