#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	
	int nn;
	cin>>nn;
	getchar();
	while(nn--){
		string a;
		getline(cin,a);
		stringstream ss(a);
		int aa[30];
		int n=0,sum=0;
		int dp[205]={};
		while(ss>>aa[n]){
			sum+=aa[n];
			n++;
		}
		//cout<<sum<<endl;
		if(sum&1){
			cout<<"NO"<<endl;
		}else{
			sum/=2;
			dp[0]=1;
			for(int i=0;i<n;i++){
				for(int j=sum;j>=aa[i];j--){
					if(dp[j-aa[i]]){
						dp[j]=1;
					}
				}
			}
			if(dp[sum])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		
	}
}
