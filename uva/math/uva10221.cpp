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
	¾l©¶©w²z : a^2 = b^2 + c^2 -2*b*c*cos(a)
*/
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string in; double a,b;
	while(cin>>a>>b>>in){
		if(b>180)b=360-b;
		a+=6440.;
		if(in[0]=='m'){
			b/=60;
		} 
		double arc = PI*2*a*b/360;
		double chord = sqrt(a*a+a*a-2*a*a*cos(PI*b/180.));
		printf("%.6lf %.6lf\n",arc,chord);
		
	}
}

