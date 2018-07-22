#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;
int main(){
	string in,buf;
	set<string> list;
	while(cin>>in){
		for(int i=0;i<in.length();i++){
			if(isalpha(in[i])) in[i]=tolower(in[i]);
			else in[i]=' ';	
		}
		stringstream ss(in);
		while(ss>>buf) list.insert(buf);
	}
	for(set<string>::iterator it=list.begin();it!=list.end();it++){
		cout<<*it<<endl;
	}
}
