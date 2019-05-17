#include<iostream>
using namespace std;
const int MAXN = 1000006;
int pn=0,vis[MAXN],nn;
long long in,prime[MAXN],l,u;
int main(){
    for(int i=2;i<MAXN;i++){
        if(vis[i])continue;
        prime[pn++]=i;
        for(int j=i;j<MAXN;j+=i){
            vis[j]=1;
        }
    }
    cin>>nn;
    while(nn--){
        cin>>l>>u;
        long long ans=0;
        for(int i=0;i<pn;i++){
            for(long long j=prime[i]*prime[i];j<=u;j*=prime[i])
                if(j>=l)ans++;
        }
        cout<<ans<<endl;
    }
}