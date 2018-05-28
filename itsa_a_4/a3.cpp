#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int n,st;
    node(int nn,int sst){
        n=nn;
        st=sst;
    }
};
int main(){
    int nn;
    cin>>nn;
    while(nn--){
        int n,a,b;
        vector<int> edg[10005];
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            edg[a].push_back(b);
            edg[b].push_back(a);
        }
        /*cout<<edg[1].size()<<endl;
        for(int i=0;i<edg[1].size();i++)
            cout<<edg[1][i]<<" ";
        cout<<endl;*/
        int minn = 0x31313131;
        int mind = -1;
        for(int i=0;i<n;i++){
            if(edg[i].size()<2)continue;
            queue<node> q;
            int count=0;
            int st=1;
            int vis[10005]={};
            vis[i]=1;
            node aa(i,st);
            q.push(aa);
            while(!q.empty()){
                node f=q.front();
                vis[f.n]=1;
                q.pop();
                //cout<<edg[f].size()<<endl;
                for(unsigned int j=0;j<edg[f.n].size();j++){
                    if(!vis[edg[f.n][j]]){
                        node bb(edg[f.n][j],f.st+1);
                        q.push(bb);
                        //cout<<i<<" "<<f.n<<" "<<edg[f.n][j]<<" "<<f.st<<endl;
                        count+=f.st;
                    }
                }
            }
            cout<<i<<" "<<count<<endl;
            if(count<minn){
                mind = i;
                minn = count;
            }
        }
        cout<<mind<<endl;
    }
}