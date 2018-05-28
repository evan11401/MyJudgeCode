/*
ID: evan11401
TASK: numtri
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

int main (){
	ofstream fout ("numtri.out");
        ifstream fin ("numtri.in");
	int a[1000][1000];
	int n;
	fin >>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			fin>>a[i][j];
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
		}
	}
	fout<<a[0][0]<<endl;

	return 0;
}
