/*
ID: evan11401
TASK: combo
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
int m;
bool ok(int a, int b) {
    if(abs(a-b) <= 2 || abs(a-b) >= m-2) return true;
    return false;
}
int v[105][105][105];

int main (){
	ofstream fout ("combo.out");
    ifstream fin ("combo.in");
	int s1,s2,s3,q1,q2,q3;
	fin >> m >> s1>> s2>>s3>>q1>>q2>>q3;
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				int a=i,b=j,c=k;
				if(!v[a][b][c]){
					if((ok(i, s1) && ok(j, s2) && ok(k, s3))
                        || (ok(i, q1) && ok(j, q2) && ok(k, q3))) {
//                        	fout<< i<<" "<<j<< " "<< k<<endl; 
                            ans++;
                            v[i][j][k] = true;
                        }
				}
				
			}
		}
	}
	fout<<ans<<endl;
	
	
	return 0;
}
