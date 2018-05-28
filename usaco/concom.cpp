/*
ID: evan11401
LANG: C++
TASK: concom
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#define mp make_pair
using namespace std;


int main()
{
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int n;
    int ctrls[105][105]={};
   	queue<pair<int,int> > q;
    fin >> n;
    while(n--){
    	int a,b,per;
    	fin>>a>>b>>per;
    	ctrls[a][b] = per;
    	if(per>50){
    		q.push(mp(a,b));
		}
	}
	while(!q.empty()){
		int s = q.front().first;
		int e = q.front().second;
		q.pop();
		for(int i=1;i<=100;i++){
			if(ctrls[s][i]<=50&&s!=i){
				ctrls[s][i]+=ctrls[e][i];
				if(ctrls[s][i]>50)
					q.push(mp(s,i));
			}
		}	
	}
	
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			if(ctrls[i][j]>50&&i!=j)
				fout<<i<<" "<<j<<endl;
    
    return 0;
}
