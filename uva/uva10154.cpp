#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN =6000;
struct Turtle{
    int w,p;
}tur[MAXN];
bool cmp(Turtle a,Turtle b){
    return a.p < b.p;
}
int main(){
    int n=0,w,p,i,j;
    while(cin>>tur[n].w>>tur[n].p){
        n++;
    }
    sort(tur,tur+n,cmp);
    int dp[MAXN];
    for(i = 0; i <= n; i++)
        dp[i] = 0xfffffff;
    dp[0]=0;
    for(i=0;i<n;i++){
        for(j=n;j>=1;j--){
            if(dp[j-1]+tur[i].w <= tur[i].p){
                dp[j] = min(dp[j],dp[j-1]+tur[i].w);
            }
        }
    }
    for(i=n;i>=0;i--)
        if(dp[i]!=0xfffffff)break;
    cout<<i<<endl;
}