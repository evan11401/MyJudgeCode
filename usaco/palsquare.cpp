/*
ID: evan11401
TASK: palsquare
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

string convert(string str){
	reverse(str.begin(), str.end());
	return str;
}

char tochar(int c){
	if(c>=10){
		return c-10 + 'A';
	}else{
		return c+'0';
	}
}
string toBase(int b,int base){
	string ret;
	while(b>=base){
		ret+=tochar(b%base);
		b/=base;
	}
	ret +=tochar(b%base);
	ret = convert(ret);
	return ret;
}

int main (){
	ofstream fout ("palsquare.out");
        ifstream fin ("palsquare.in");
	int base;
	fin>>base;
	for(int i=1;i<=300;i++){
		int b=i,bsq=i*i;
		string bBase = toBase(b,base);
		string bsqBase = toBase(bsq,base);
		//fout << b << " "<<bBase<<endl;
		if(bsqBase==convert(bsqBase)){
			fout<<bBase<<" "<<bsqBase<<endl;
		}
	}
	return 0;
}
