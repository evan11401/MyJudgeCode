/*
ID: evan11401
TASK: gift1
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
	ofstream fout ("gift1.out");
        ifstream fin ("gift1.in");
	map<string,int> total;
	vector<string> c;
	string name;
	int n,a,b;
	fin >> n;
	for(int i = 0;i<n;i++){
		fin >> name;
		total[name] = 0;
		c.push_back(name);
	}
	while(fin>>name){
		fin >>a>>b;
		if(a==0) continue;
		int pay = a/b;
		int mod = a%b;
		total[name] = total[name]-a+mod;
		while(b--){
			fin >> name;
			total[name]+=pay;
		}
	}
	for(int i=0;i<c.size();i++){
		fout << c[i] << " "<< total[c[i]] << endl;
	}
	
	return 0;
}
