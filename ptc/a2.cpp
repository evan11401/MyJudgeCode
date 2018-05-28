#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int ans[30000]={};
        int p,q,r;
        cin>>p>>q>>r;
        int aa,bb;
        cin>>aa>>bb;
        ans[0] = aa;
        ans[1] = bb;
        int i=2;
        int j;
        bool find = false;
        while(i<30000&&!find){
            int x = ans[i-2];
            int y = ans[i-1];
            ans[i] = (q*x+r*(x-y)*(x-y)+y)%p;
            //cout<<i<<" "<<ans[i]<<endl;
            i++;
            for(j=0;j<i-1;j++){
                if(j==i-2)continue;
                if(ans[j]==ans[i-2]&&ans[j+1]==ans[i-1]){
                    find = true;
                    break;
                }
            }
        }
        
        cout<<i-2-j<<endl;
    }
}