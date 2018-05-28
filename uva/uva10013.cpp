#include<iostream>
using namespace std;
int num1[1000005];
int num2[1000005];
int carry[1000005];
int ans[1000005];
int main(){
    int nn,m;
    cin>>nn;
    bool f=true;
    while(nn--){
        cin>>m;
        for(int i=m-1;i>=0;i--)
            cin>>num1[i]>>num2[i];
        for(int i=0;i<m;i++){
            //cout<<(carry[i]+num1[i]+num2[i])<<endl;
            ans[i]=(carry[i]+num1[i]+num2[i])%10;
            carry[i+1] = (carry[i]+num1[i]+num2[i])/10;
        }
        if(f){
            f=false;
        }else{
            cout<<endl;
        }
        for(int i=m-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<endl;

    }
}