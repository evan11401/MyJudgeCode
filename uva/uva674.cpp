#include<iostream>
using namespace std;
int main(){
	int bag[7500];
	int coins[]={1,5,10,25,50};	
	int n,ans,i,j;
	for(i=0;i<7500;i++)bag[i]=1;
	for(i=1;i<5;i++){
		for(j=1;j<7500;j++){
			if(j>=coins[i])bag[j]+=bag[j-coins[i]];
		}
	}
	while(cin>>n){
		cout<<bag[n]<<endl;
	}
} 
