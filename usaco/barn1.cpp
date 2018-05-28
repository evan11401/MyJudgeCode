/*
ID: evan11401
TASK: barn1
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
bool  cmp( int a , int b )  
{  
    return a > b ;  
}  
int main (){
	ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
	int m,s,c;
	fin >> m >> s>> c;
	
	if(m>c){
		fout << c << endl;
		return 0;
	}
	vector<int> st;
	vector<int> gaps;
	int a,b,f;
	for(int i=0;i<c;i++){
		fin >>a;
		st.push_back(a);
	} 
	sort(st.begin(),st.end());
	for(int i=1;i<c;i++){
		gaps.push_back(st[i]-st[i-1]-1);
		
	}
	sort(gaps.begin(),gaps.end(),cmp);
	int to=st[c-1]-st[0]+1;
//	fout << to<<endl;
	for( int i = 0 ; i < m - 1 ; i ++ )  
        to -= gaps[i] ;
	fout << to<< endl;
	return 0;
}
