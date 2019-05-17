#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string in;
    while(cin>>in&&in!="#"){
        if(next_permutation(in.begin(),in.end())==0){
            cout<<"No Successor";
        }else{
            cout<<in;
        }
        cout<<endl;
    }
}