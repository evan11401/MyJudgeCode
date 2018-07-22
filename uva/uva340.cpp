#include<iostream>
#include<math.h> 
#include<time.h>
#include<string.h>
#include <algorithm>
using namespace std;
int main(){
	int ans[1005]={};
	int in[1005]={};
	bool use[1005]={};
	
	int n,num=1;
	while(cin>>n&&n!=0){
		cout<<"Game "<<num++<<":"<<endl;
		for(int i=0;i<n;i++){
			cin>>ans[i];
		} 
		bool isEnd=false;
		do{
			int nums[10]={};
			for(int i=0;i<n;i++){
				cin>>in[i];
				use[i]=false;				
			}
			isEnd=true;
			int a=0,b=0;
			for(int i=0;i<n;i++){
				if(in[i]!=0){
					isEnd=false;
				}
				if(in[i]==ans[i]){
					a++;
					use[i]=true;
				}else{
					nums[ans[i]]++;
				}
			}
			if(isEnd)break;
			for(int i=0;i<n;i++){
				if(use[i])continue;
				else if(nums[in[i]]){
					b++;
					nums[in[i]]--;
				}
			}						
			cout<<"    ("<<a<<","<<b<<")"<<endl;
		}while(1);
	}
} 
