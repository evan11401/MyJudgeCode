#include<iostream>
using namespace std;
typedef long long LLI;
LLI sum0(LLI n){
    LLI N=n,sum=0;
    LLI left=1,mid,right=1;
    while(N>=10){
        mid = N%10;
        N/=10;
        if(mid)sum+=(N*left);
        else sum+=((N-1)*left+n%right+1);
        left*=10;
        right*=10;
    }
    return sum;
}
int main(){
    LLI m,n;
    while(cin>>m>>n&&m>=0){
        LLI ans = sum0(n) - sum0(m-1);
        if(m==0)ans++;
        cout<<ans<<endl;
    }
}