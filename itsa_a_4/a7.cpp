#include<iostream>
#include<vector>
using namespace std;
int c, p;             // X的點數目、Y的點數目
int mx[105], my[105];   // X各點的配對對象、Y各點的配對對象
bool vy[105];           // 記錄Graph Traversal拜訪過的點
bool adj[105][105];     // 精簡過的adjacency matrix
 
// 以DFS建立一棵交錯樹
bool DFS(int x)
{
    for (int y=0; y<p; y++)
        if (adj[x][y] && !vy[y])
        {
            //cout<<"aaa"<<endl;
            vy[y] = true;

            // 找到擴充路徑
            if (my[y] == -1 || DFS(my[y]))
            {
                mx[x] = y; my[y] = x;
                return true;
            }
        }
    return false;
}

int main(){
    int nn;
    cin>>nn;
    while(nn--){
        vector<pair<int,int> > peo;
        peo.resize(100);
        vector<pair<int,int> > car;
        car.resize(100);
        
        cin>>c>>p;
        for(int i=0;i<c;i++){
            int x,y;
            cin>>x>>y;
            car[i]=make_pair(x,y);
        }
        for(int i=0;i<p;i++){
            int x,y;
            cin>>x>>y;
            peo[i]=make_pair(x,y);
        }
        for(int i=0;i<100;i++){
            mx[i]=-1;
            my[i]=-1;
            vy[i]=0;
            for(int j=0;j<100;j++)
                adj[i][j]=0;
        }
        for(int i=0;i<c;i++){
            int x = car[i].first;
            int y = car[i].second;
            for(int j=0;j<p;j++){
                int px = peo[j].first;
                int py = peo[j].second;
                if((abs(x-px)+abs(y-py))<=5){
                    adj[i][j]=1;
                }
            }
        }
        /*
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int ans = 0;
        for (int x=0; x<c; x++)
        {
            if (DFS(x)) ans++;
        }
        
        cout<<ans<<endl;
    }
}