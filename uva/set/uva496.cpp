#include<iostream>
#include<set>
#include<sstream>
#include<string>
#include <algorithm>
using namespace std;
stringstream ss;
string input;
int in;
void getIn(set<int> *sett){
	ss<<input;
	while(ss>>in){
		sett->insert(in);
	}
	ss.clear();
}
void printAll(set<int> sett){
	for(set<int>::iterator it = sett.begin();it!=sett.end();it++){
		cout<<*it<<endl;
	}
}
//union =u
//u=a+b disjoint
//u=a>b a include b
//u=b>a b include a
//u=a=b a equal b 
int main(){		
	int ca=0,cb=0,cc=0;
	set<int> setA,setB,setC;
	while(getline(cin,input)){			
		setA.clear();
		setB.clear();
		setC.clear();
		
		getIn(&setA);
		getline(cin,input);		
		getIn(&setB);
		ca = setA.size();
		cb = setB.size();
				
		set_union(setA.begin(),setA.end(),setB.begin(),setB.end(),inserter(setC,setC.begin()));
		cc = setC.size();
		if(cc == ca+cb){
			cout<<"A and B are disjoint\n";
		}else if(cc==ca&&cc>cb){
			cout<<"B is a proper subset of A\n";
		}else if(cc==cb&&cc>ca){
			cout<<"A is a proper subset of B\n";
		}else if(cc==ca && cc==cb){
			cout<<"A equals B\n";
		}else{
			cout<<"I'm confused!\n";
		}
		
	}
} 
