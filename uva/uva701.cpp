#include<iostream>
#include<cmath>
using namespace std;
int main(){
    unsigned n;
    while(cin>>n){
        double u = (double)n;
        int i = log10(u)+2;
        while(1){
            int low = floor(log2(u)+i*log2(10));
            int high = ceil(log2(u+1)+i*log2(10));
            if(high>low+1){
                cout<<low+1<<endl;
                break;
            }
            i++;
        }
    }
}