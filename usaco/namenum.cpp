/*
ID: evan11401
TASK: namenum
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

char transform(char a){
	switch(a){
		case 'A':
		case 'B':
		case 'C':
			return '2';
		case 'D':
		case 'E':
		case 'F':
			return '3';
		case 'G':
		case 'H':
		case 'I':
			return '4';
		case 'J':
		case 'K':
		case 'L':
			return '5';
		case 'M':
		case 'N':
		case 'O':
			return '6';
		case 'P':
		case 'R':
		case 'S':
			return '7';
		case 'T':
		case 'U':
		case 'V':
			return '8';
		case 'W':
		case 'X':
		case 'Y':
			return '9';
		default:
			return '1';
	}
}

int main (){
	ofstream fout ("namenum.out");
        ifstream fin ("namenum.in");
	ifstream n ("dict.txt");
	map<string,string> namelist;
	map<string,string>::iterator iter;
	string name;
	while(n >> name){
		string nameNum;
		for(int i=0;i<name.length();i++){
			nameNum += transform(name[i]);
		}
		namelist[name] = nameNum;
	}
	string in;
	fin >> in;
	bool found=false;
	for(iter = namelist.begin();iter!=namelist.end();iter++){
		if(iter->second==in){
			fout<<iter->first<<endl;
			found = true;
		}
		//fout<<iter->first<<" "<<iter->second<<endl;
	}
	if(!found){
		fout<<"NONE"<<endl;
	}
	
	return 0;
}
