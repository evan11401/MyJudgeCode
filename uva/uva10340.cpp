#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    while(cin>>s>>t){
        int j=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[j])j++;
        }
        if(j==s.size())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}