#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n<2)return false;
    for(int c=2;c<=sqrt(n);c++){
        if(n%c==0)return false;
    }
    return true;
}
int main(){
    int in;
    
    while(cin>>in){
        if(in<8){
            cout<<"Impossible.\n";
        }else{
            if(in&1){
                cout<<"2 3 ";
                in-=5;
            }else{
                cout<<"2 2 ";
                in-=4;
            }
            for(int i=2;i<in;i++){
                if(isPrime(in-i) && isPrime(i)){
                    cout<<i<<" "<<in-i<<endl;
                    break;
                }
            }
        }
    }
}