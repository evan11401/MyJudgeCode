#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
using namespace std;
int main(){
	int num[1005]={};
	vector<string> words[1005];
	string line,in;
	int n=0;
	while(getline(cin,line)){
		stringstream ss(line);
		int i=0;
		while(ss>>in){
			int len = in.length();
			num[i]=max(num[i],len);
			i++;
			words[n].pb(in);
		}
		n++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<words[i].size();j++){
			if(j==words[i].size()-1)
				printf("%s",words[i][j].c_str());
			else
				printf("%*s",-num[j]-1,words[i][j].c_str());
		}
		printf("\n");
	}
}
