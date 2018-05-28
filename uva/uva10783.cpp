#include<iostream>
using namespace std;
int main(){
    int nn;
    cin>>nn;
    for(int j=1;j<=nn;j++){
        int a,b;
        cin>>a>>b;
        if(!(a&1))a++;
        if(!(b&1))b--;
        int sum=0;
        for(int i=a;i<=b;i+=2){
            sum+=i;
        }
        cout<<"Case "<<j<<": "<<sum<<endl;
    }
}