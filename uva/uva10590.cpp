#include<iostream>
using namespace std;
int main(){
    int dp[5001];
    for(int i=0;i<5001;i++)dp[i]=0;
    dp[0]=1;
    for(int i=1;i<5001;i++){
        for(int j=i;j<5001;j++){
            dp[j] = dp[j]+dp[j-i];
        }
    }
    int in;
    while(cin>>in){
        cout<<dp[in]<<endl;
    }
}