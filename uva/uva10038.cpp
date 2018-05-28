#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int nn;
    int a[3005]={};
    while(cin>>nn){
        int ans[3005]={};
        cin>>a[0];
        bool f=true;
        for(int i=1;i<nn;i++){
            cin>>a[i];
            ans[abs(a[i]-a[i-1])]++;
        }
        
        for(int i=1;i<nn;i++){
            if(ans[i]!=1&&!ans[i]){
                f=false;
                break;
            }
        }
        if(f) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }
}