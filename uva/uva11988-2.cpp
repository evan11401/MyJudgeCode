#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<list>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int MAXN = 100000+5;

int main(){
	string input;
	while(cin>>input){
		list<char> text;
		list<char>::iterator it;
		it = text.begin();
		
		for(int i=0;i<input.length();i++){
			char c = input[i];
			if(c=='[')it = text.begin();
			else if(c==']')it = text.end();
			else{
				text.insert(it,c);
			}
		}
		
		for(it = text.begin();it!=text.end();it++){
			cout<<*it;
		}
		cout<<endl;
	}
}
