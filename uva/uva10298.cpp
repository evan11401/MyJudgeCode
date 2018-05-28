#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(cin>>s&&s[0]!='.'){
        int ans;
        for(int i=1;i<s.size();i++){
            if(i==s.size()-1){
                cout<<1<<endl;
                break;
            }
            if(s.size()%i!=0)continue;
            string tmp,an;
            for(int j=0;j<i;j++)tmp+=s[j];
            for(int j=0;j<s.size()/i;j++)an+=tmp;
            if(an==s){
                cout<<s.size()/i<<endl;
                break;
            }
        }
    }
}