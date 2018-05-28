#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int nn;
    cin>>nn;
    while(nn--){
        int n,d;
        int num[105];
        vector<int> aaa;
        cin>>n>>d;
        for(int i=0;i<n;i++)
            cin>>num[i];
        sort(num,num+n);
        int aa = n/2;
        bool prt = false;
        for(int i=0;i<n;i++){
            int now = num[i];
            int st = now - d;
            int en = now + d;
            int ans=0;
            for(int j=0;j<n;j++){
                if(num[j]>=st&&num[j]<=en)ans++;
                if(num[j]>en)break;
            }
            if(ans>aa){
                aaa.push_back(now);
            }
        } 
        sort(aaa.begin(),aaa.end());
        if(aaa.size()==0)
            cout<<"No"<<endl;
        else
            cout<<aaa[0]<<" "<<aaa[aaa.size()-1]<<endl;
    }
}