#include<iostream>
#include<cstdio>
using namespace std;
int prime(int n){
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
int main(){
    int num[10010]={};
    int a,b;
    for(int i=0;i<10010;i++){
        num[i] = prime(i*i+i+41);
    }
    while(cin>>a>>b){
        int sum=0;
        for(int i=a;i<=b;i++){
            sum+=num[i];
        }
        printf("%.2f\n",sum*1.0/(b-a+1)*100+1e-8); 
    }
}