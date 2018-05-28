/*
ID: evan11401
TASK: ariprog
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
struct po{
	int str,def;
};
int cmp(po a,po b){
	if(a.def!=b.def) return a.def <b.def;
	else return a.str<b.str;
}

int main (){
	ofstream fout ("ariprog.out");
        ifstream fin ("ariprog.in");
	
	vector<po> ans; 
	int w[500000]={};
	int n,m;
	fin >> n>> m;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			int a=i*i+j*j;
			w[a]=1;
		}
	}

	int str,def;
	int maxx = m*m*2;
	for(int i=0;i<maxx;i++){
		for(int j=1;i+(n-1)*j<=maxx;j++){
			str=i;
			def = j;
			for(int q=1;q<=n;q++){
				if(w[str]){
					str+=def;
				}else break;
				if(q==n){
					po z;
					z.str=i;
					z.def=j;
					ans.push_back(z);
				}
			}

		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size()==0){
		fout<<"NONE"<<endl;
	}else
		for(int i=0;i<ans.size();i++){
			fout<<ans[i].str<<" "<<ans[i].def<<endl;
		}

	return 0;
}
