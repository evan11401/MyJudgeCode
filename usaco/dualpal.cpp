/*
ID: evan11401
TASK: dualpal
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
	ofstream fout ("dualpal.out");
        ifstream fin ("dualpal.in");
	int base,num;
	fin>>num>>base;
	int a=1;
	for(int i=base+1;i<=100000&&a<=num;i++){
		int b=i,n=0;
		//fout << b << " "<<bBase<<endl;
		for(int j=2;j<=10;j++){
			string bbase = toBase(b,j);
			if(bbase==convert(bbase)&&++n>=2){
				//fout<<j<<" "<<b<<" "<<bbase<<endl;
				fout<<i<<endl;
				a++;
				break;
			}
		}
	}
	return 0;
}
