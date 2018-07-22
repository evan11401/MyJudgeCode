#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int num;
	string com,per;
	while(cin>>num&&num!=-1){
		cin>>com>>per;
		cout<<"Round "<<num<<endl;
		int used[26]={};
		for(int i=0;i<com.length();i++)
			used[com[i]-'a']++;
		int live=7;
		int guess[26]={};
		bool win=false;
		for(int i=0;i<per.length()&&!win&&live;i++){
			if(used[per[i]-'a']){
				if(!guess[per[i]-'a']){
					guess[per[i]-'a']++;
				}else{
					live--;
				}
			}else{
				live--;
			}
			for(int j=0;j<26;j++){
				if(used[j]){
					if(guess[j]){
						win=true;
					}else{
						win=false;
						break;
					}
				}
			}
		}
//		for(int j=0;j<26;j++){
//			cout<<used[j];
//		}
//		cout<<endl;
//		for(int j=0;j<26;j++){
//			cout<<guess[j];
//		}
		//cout<<endl<<live<<endl;
		if(win){
			cout<<"You win.\n";
		}else{
			if(live)cout<<"You chickened out.\n";
			else cout<<"You lose.\n";
			
		}
	}
	
} 
