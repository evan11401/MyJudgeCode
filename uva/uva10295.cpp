#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    int nn,mm;
    cin>>nn>>mm;
    map<string,int> costArr;
    while(nn--){
        int m;
        string word;
        cin>>word>>m;
        costArr[word]=m;
    }
    while(mm--){
        int sum=0;
        string in;
        while(cin>>in&&in[0]!='.'){
            if(costArr[in]!=0){
                sum+=costArr[in];
            }
        }
        cout<<sum<<endl;
    }
}