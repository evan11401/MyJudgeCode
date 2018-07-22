#include<iostream>
#include<string>
using namespace std;
int main(){
    int nn;
    cin>>nn;
    while(nn--){
        int paper[550][550]={};
        int n,m;
        cin>>n>>m;
        string in;
        for(int i=1;i<=n;i++) {
            cin>>in;
            for(int j=0;j<m;j++){
                paper[i][j+1]=in[j]-'0';
            }
        }
       
            
        for(int i=n-1;i>1;i--){
            for(int j=m-1;j>1;j--){
                if(paper[i][j]==1){
                    int zre=0;
                    if(paper[i][j+1]==0)zre++;
                    if(paper[i][j-1]==0)zre++;
                    if(paper[i+1][j]==0)zre++;
                    if(paper[i-1][j]==0)zre++;
                    if(zre>=2){
                        cout<<i<<" "<<j<<endl;
                        break;
                    }
                }
                
            }
        }
    }
}