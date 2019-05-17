#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LL long long
const int MAXN = 10000+5;

string input;
int p,cnt;
const int len=32;
int buf[len][len];
/*
2 1
3 4
*/
void draw(int r,int c,int w){
	char ch = input[p++];
	if(ch=='p'){
		draw(r,c+w/2,w/2);
		draw(r,c,w/2);
		draw(r+w/2,c,w/2);
		draw(r+w/2,c+w/2,w/2);
	}else if(ch=='f'){
		for(int i=r;i<r+w;i++)
			for(int j=c;j<c+w;j++){
				if(buf[i][j]==0){
					buf[i][j]=1;cnt++;
				}
			}
	}
}
int main(){
	int a;
	cin>>a;
	while(a--){
		cnt=0;
		memset(buf,0,sizeof(buf));
		for(int i=0;i<2;i++){
			cin>>input;
			p=0;
			draw(0,0,len);
		}
		cout<<"There are "<<cnt<<" black pixels.\n";
	}
}
