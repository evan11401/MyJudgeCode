/*
ID: evan11401
TASK: skidesign
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
	ofstream fout ("skidesign.out");
        ifstream fin ("skidesign.in");

	int a;
	vector<int> hills;
	fin >>a;
	for(int i=0;i<a;i++){
		int q;
		fin >> 	q;
		hills.push_back(q);
	}
	sort(hills.begin(),hills.end());
	int ans = 0x3f3f3f3f;
	int maxx =hills[a-1]; 
	for(int i=0;i<=maxx;i++){
		int sum=0;
		for(int j=0;j<a;j++){
			if(hills[j]<i && i-hills[j]>17){
				sum += pow(i-hills[j]-17,2);
			}
			if(hills[j]>i){
				sum += pow(hills[j]-i,2);
			}
		}
		ans = min(sum,ans);
	}
	fout<<ans<<endl;

	return 0;
}
