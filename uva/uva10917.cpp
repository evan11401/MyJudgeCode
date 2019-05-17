#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod = 1000000000 + 7;
const int INF = 1000000000;
const int maxn = 1000 + 10;
int T,n,m,d[maxn],vis[maxn],done[maxn],kase=0;
ll dp[maxn];
struct node {
    int u, dist;
    node(int u=0, int dist=0):u(u),dist(dist) {}
    bool operator < (const node& rhs) const {
        return dist > rhs.dist;
    }
};
vector<node> g[maxn];
void BFS() {
    priority_queue<node> q;
    q.push(node(2, 0));
    for(int i=1;i<=n;i++) d[i] = INF, done[i] = false;
    d[2] = 0;
    while(!q.empty()) {
        node u = q.top(); q.pop();
        if(done[u.u]) continue;
        done[u.u] = true;
        int len = g[u.u].size();
        for(int i=0;i<len;i++) {
            node v = g[u.u][i];
            if(d[v.u] > d[u.u] + v.dist) {
                d[v.u] = d[u.u] + v.dist;
                q.push(node(v.u, d[v.u]));
            }
        }
    }
}
ll solve(int x) {
    ll& ans = dp[x];
    if(x == 2) return 1;
    if(vis[x] == kase) return ans;
    vis[x] = kase;
    ans = 0;
    int len = g[x].size();
    for(int i=0;i<len;i++) {
        node v = g[x][i];
        if(d[v.u] < d[x]) {
            ans += solve(v.u);
        }
    }
    return ans;
}
int u,c, v;
int main() {
    while(~scanf("%d",&n) && n) {
        scanf("%d",&m);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&u,&v,&c);
            g[u].push_back(node(v, c));
            g[v].push_back(node(u, c));
        }
        ++kase;
        BFS();
        printf("%lld\n",solve(1));
    }
    return 0;
}

