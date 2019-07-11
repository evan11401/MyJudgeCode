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
#define F(x) (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u)
#define EPS 1e-7
using namespace std;

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int p, q, r, s, t, u;
	while(cin>>p>> q>> r>> s>> t>> u){
		double a=0.,b=1.,mid=0.5;
		double fmid,fa = F(a),fb = F(b);
		if(fabs(fa)<=EPS)
			cout<<"0.0000\n";
		else if(fabs(fb)<=EPS)
			cout<<"1.0000\n";
		else if(fa*fb<0){
			while(b-a>=EPS){
				fmid = F(mid);
				if(fabs(fmid)<=EPS)
					break;
				else if(fmid<0)
					b=mid;
				else
					a=mid;
				mid = (a+b)/2;
				
			}
			printf("%.4lf\n",mid);
		}else{
			printf("No solution\n");
			
		}
		
		
	}
}

