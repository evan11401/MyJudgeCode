#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string repr(string in){
	for(int i=0;i<in.length();i++)in[i]=tolower(in[i]);
	sort(in.begin(),in.end());
	return in;
}
int main(){
	string in;
	map<string,int> list;
	vector<string> words;
	while(cin>>in&&in!="#"){
		words.push_back(in);
		in = repr(in);
		list[in]++;
	}
	vector<string> ans;
	for(int i=0;i<words.size();i++){
		if(list[repr(words[i])]==1)ans.push_back(words[i]);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	} 
	
}
