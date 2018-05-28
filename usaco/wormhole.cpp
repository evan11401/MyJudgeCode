/*
ID: evan11401
TASK: wormhole
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX_N 12

using namespace std;
struct point
{
    int x;
    int y;
};
 
int compare(point a, point b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}
 
 
int n;
int picked = 0;
int ans = 0;
vector<point> v;
int bucket[12] = {0};
int pairs[12] = {0};
 
void dfs()
{
    if (picked != n)
    {
        int i = 0;
        while (bucket[i]) ++i;
        pairs[picked++] = i;
        bucket[i] = 1;
        for (int j = i + 1; j < n; ++j)
        {
            if (bucket[j] == 0)
            {
                pairs[picked++] = j;
                bucket[j] = 1;
                dfs();
                --picked;
                bucket[j] = 0;
            }
        }
        bucket[i] = 0;
        --picked;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int in = i;
            int j;
            for (j = 0; j < n; ++j)
            {
                int r = (in%2 == 0) ? pairs[in + 1] : pairs[in - 1];
                if (r == n - 1 || v[r + 1].y != v[r].y)
                    break;
                
                for (int k = 0; k < n; ++k)
                {
                    if (pairs[k] == r + 1)
                    {
                        in = k;
                        break;
                    }
                }
            }
            
            if (j == n)
            {
                ++ans;
                break;
            }
        }
    }
}
 
int main()
{
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin >> n;
    for (int i = 0; i < n; ++i)
    {
        point p;
        fin >> p.x >> p.y;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compare);
    dfs();
    
    fout << ans << endl;
    
    return 0;
}
