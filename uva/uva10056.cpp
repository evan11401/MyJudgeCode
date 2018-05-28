#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int nn,n,i;
    double p,pi;
    cin>>nn;
    while(nn--){
        cin>>n>>p>>i;
        if(p<0.00001){
            cout<<"0.0000\n";
        }else{
            pi=pow(1-p,i-1)*p/(1-pow(1-p,n));
            printf("%.4lf\n",pi);
        
        }
    }
}