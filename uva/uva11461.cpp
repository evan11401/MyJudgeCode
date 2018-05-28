#include<iostream>
using namespace std;
int main(){
    int a[100005]={};
    for(int i=1;i*i<100000;i++){
        a[i*i]=1;
    }
    for(int i=1;i<100000;i++){
        a[i]+=a[i-1];
    }
    int x,y;
    while(cin>>x>>y&&x!=0&&y!=0){
        cout<<a[y]-a[x-1]<<endl;
    }
}