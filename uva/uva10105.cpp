#include<iostream>
using namespace std;
const int N=15;
int c[N][N];
void init(){
    for(int i=0;i<N;i++)c[i][0]=c[i][i]=1;
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];

    for(int i=1;i<N;i++)
        for(int j=0;j<N;j++){
            if(j>i)break;
            cout<<i<<" "<<j<<":"<<c[i][j]<<endl;
        }
}
int main(){
    init();
    int n,k,ans,in;
    while(cin>>n>>k){
        ans=1;
        for(int i=0;i<k;i++){
            cin>>in;
            ans*=c[n][in];
            n-=in;
        }
        cout<<ans<<endl;
    }
}