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
	int n,num;
	cin>>n;
	while(n--){
		set<string> words; 
		int nums[20]={};
		cin>>num;
		string w="",ans="";
		for(int i=0;i<num;i++){
			cin>>nums[i];
			ans+='0';
			w+=to_string(nums[i]);
		}
		//cout<<ans<<endl;
		while(1){
			if(words.count(w)){
				cout<<"LOOP\n";
				break;
			}
			if(w==ans){
				cout<<"ZERO\n";
				break;
			}
			words.insert(w);
			w="";
			int first=nums[0];
			for(int i=0;i<num;i++){
				if(i==num-1)nums[i] = abs(nums[i]-first);
				else nums[i] = abs(nums[i]-nums[i+1]);
				w+=to_string(nums[i]);
			}
			//cout<<w<<endl;
		}
		
	}
}
