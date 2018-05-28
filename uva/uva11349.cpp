#include<iostream>
using namespace std;
int main(){
    int nn;
    cin>>nn;
    long long a[105][105];
    for(int e=1;e<=nn;e++){
        char q,w;
        int n;
        bool f=true;
        cin>>q>>w>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j]<0)f=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=a[n-1-i][n-1-j]){
                    f=false;
                    break;
                }
            }
        }
        if(f)cout<<"Test #"<<e<<": Symmetric."<<endl;
        else cout<<"Test #"<<e<<": Non-symmetric."<<endl;
    }
}