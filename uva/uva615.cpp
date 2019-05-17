#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
const int MAXN = 100000;
 
vector<int> graph[MAXN + 1];
bool isNode[MAXN + 1];
int in[MAXN + 1];
bool visit[MAXN + 1];
bool isTree;
 
void dfs(int u)
{
    visit[u] = true;
     
    for(int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
         
        if(visit[v])
        {
            isTree = false;
            return;
        }
         
        dfs(v);
        if(!isTree) return;
    }
}
 
int main()
{
    int Case = 0;
    int u, v;
     
    while(cin >> u >> v)
    {
        if(u < 0 && v < 0) break;
         
        for(int i = 1; i <= MAXN; i++)
        {
            graph[i].clear();
            isNode[i] = false;
            in[i] = 0;
            visit[i] = false;
        }
         
        while(u != 0 && v != 0)
        {
            graph[u].push_back(v);
            isNode[u] = isNode[v] = true;
            in[v]++;
             
            cin >> u >> v;
        }
         
        isTree = true;
         
        for(int i = 1; i <= MAXN; i++)
        {
            if(isNode[i] && in[i] == 0)
            {   
                dfs(i);
                break;
            }
        }
        for(int i = 1; i <= MAXN; i++)
        {
            if(isNode[i] && !visit[i])
            {
                isTree = false;
                break;
            }
        }
         
        cout << "Case " << ++Case << " ";
        if(isTree)
            cout << "is a tree.";
        else
            cout << "is not a tree.";
             
        cout << endl;
         
    }
 
    return 0;
}
