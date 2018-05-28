#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,in;
        cin>>a>>b;
        int maxc = 1;
        int maxx = 0;
        for(int i=1;i<=a;i++){
            int num=0;
            for(int j=0;j<b;j++){
                cin>>in;
                if(in)num++;
            }
            if(num>maxx){
                maxc = i;
                maxx = num;
            }
        }
        cout<<"Class "<<maxc<<" has "<<maxx<<" boys."<<endl;
    }
}