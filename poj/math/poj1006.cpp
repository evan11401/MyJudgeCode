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
#define MAX 21252 
using namespace std;
/*
x % 23 == p¡F x % 28 == e¡F x % 33 == i¡F

33 * 28 * a % 23 = 1¡Aa = 6¡F 33 * 28 * 6?= 5544
23 * 33 * b % 28 = 1¡A b = 19¡F23 * 33 * 19 = 14421
23 * 28 * c % 33 = 1¡A c = 2¡F ?23 * 28 * 2 = 1288

¨º¤\x = 5544 * p + 14421 * e + 1288 * i



*/
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int p,e,i,d,n,count=1;
	while(cin>>p>>e>>i>>d){
		
		if(p == -1 && e == -1 && i == -1 && d == -1)
		{
			break;
		}
		cout<<"Case "<<count++<<": the next triple peak occurs in ";
		n = ( 5544 * p + 14421 * e + 1288 * i - d ) % MAX;
		if( n <= 0 ) 
		{
			n += MAX;
        }
        cout<<n<<" days.\n";
	}
}

