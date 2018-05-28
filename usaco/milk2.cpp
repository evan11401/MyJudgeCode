/*
ID: evan11401
TASK: milk2
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int store[1000005];

int main (){
	ofstream fout ("milk2.out");
        ifstream fin ("milk2.in");
	int N,M;
 	fin >> N;
	int maxx=0,minn=0,num=0;
	int start,end,s,e;
	while(N--){
		fin>>start>>end;
		if(num==0){
			s=start;
			e=end;
		}
		else{
			s=min(start,s);
			e=max(end,e);
		}
		for(int i=start;i<end;i++){
			store[i]=1;
		}
		num++;
	}
	cout << "start:"<<s<<endl;
	cout << "end:"<<e<<endl;
	for(int i=s;i<=end;i++){
		cout<<store[i];
	}
	cout<<endl;
	for(int i=s;i<=end;i++){
		if(store[i]){
			int a=1;
			for(int j=i+1;j<=end;j++){
				if(store[j]&&j<end){
					a++;
				}
				else{
					maxx = max(a,maxx);
					i=j-1;
					break;
				}
			}
		}else{
			int b=1;
			for(int j=i+1;j<=end;j++){
				if(store[j]==0&&j<end) b++;
				else{
					minn = max(b,minn);
					i=j-1;
					break;
				}
			}
		}
	}
	fout<<maxx << " " << minn<<endl;

	return 0;
}
