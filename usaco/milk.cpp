/*
ID: evan11401
TASK: milk
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

int main (){
	ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	map<int,int> total;	
	map<int,int>::iterator iter;
	string name;
	int n,a,x,y;
	fin >> n>>a;
	for(int i=0;i<a;i++){
		fin >> x>>y;
		total[x] += y;
	}
	int sell=0,num =0;
	for(iter = total.begin();iter!=total.end();iter++){
//		fout<< iter->first <<" "<< iter->second<<endl;
		if(num>=n) break;
		if(num+(iter->second)>n){
			sell+=(n-num)*(iter->first);
			num+=n-num;
		} 
		else{
			sell+=iter->first*iter->second;
			num+=iter->second;
		} 
//		fout << sell<<" "<< num <<endl;
	}
	fout << sell <<endl;
	
	return 0;
}
