#include<iostream>
using namespace std;
int main(){
    int nn;
    cin>>nn;
    char vot[1005][505];
    int live[1005];
    while(nn--){
        int p,r;
        cin>>p>>r;
        for(int i=1;i<=p;i++){
            for(int j=1;j<=r;j++){
                cin>>vot[i][j];
            }
            live[i]=1;
        }
        for(int j=1;j<=r;j++){
            /*for(int i=1;i<=p;i++){
                cout<<live[i]<<" ";
            }
            cout<<endl;*/
            int y=0,n=0;
            for(int i=1;i<=p;i++){
                if(live[i]){
                    if(vot[i][j]=='Y')y++;
                    else n++;
                }
            }
            if(y==0||n==0){
                continue;
            }else if(y==n){
                continue;
            }else if(y>n){
                for(int i=1;i<=p;i++){
                    if(vot[i][j]=='Y')live[i]=0;
                }
            }else{
                for(int i=1;i<=p;i++){
                    if(vot[i][j]=='N')live[i]=0;
                }
            }
        }
        bool ptr=false;
        for(int i=1;i<=p;i++){
            if(live[i]){
                if(!ptr){
                    cout<<i;
                    ptr=true;
                }else{
                    cout<<" "<<i;
                }
            }
        }
        cout<<endl;

    }
}