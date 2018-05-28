#include<iostream>
using namespace std;

int main()
{
    long long int s,d;
    int i;
    while(cin>>s>>d){
        for(i=0;;i++){
            long long int aa = (s+(s+i))*(i+1)/2;
            if(aa>=d){
                cout<<s+i<<endl;
                break;
            }
        }
    }
    return 0;
}
