#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int nn;
    cin>>nn;
    while(nn--){
        long long a,b,s,d;
        cin>>s>>d;
        if((s+d)&1){
            cout<<"impossible"<<endl;
        }else{
            a = (s+d)/2;
            b = (s-d)/2;
            if(a<0||b<0){
                cout<<"impossible"<<endl;
            }else{
                if(a>=b) cout<<a<<" "<<b<<endl;
                else cout<<b<<" "<<a<<endl;
            }
        }
        
    }
    return 0;
}
