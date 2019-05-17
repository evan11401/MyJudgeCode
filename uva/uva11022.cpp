#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string in;
int dp[85][85];
int dfs(int l,int r){
    if(l==r)return 1;
    if(dp[l][r])return dp[l][r];
    int i,j,k;
    //int &ret=dp[l][r];
    int ret = 0xfffffff;
    for(i=l;i<r;i++)ret=min(ret,dfs(l,i)+dfs(i+1,r));
    int sublen = r-l+1;
    for(i=1;i<=sublen;i++){
        if(sublen%i==0){
            for(k=l,j=0;k<=r;k++){
                if(in[k]!=in[j+l])break;
                j++;
                j%=i;
            }
            if(k==r+1 && r!=l+i-1)ret = min(ret,dfs(l,l+i-1));
        }
    }
    dp[l][r]=ret; 
    return ret;
}
int main(){
    while(cin>>in && in!="*"){
        memset(dp, 0, sizeof(dp));
        int len = in.size();
        cout<<dfs(0,len-1)<<endl;
    }
}
