/*
ID: evan11401
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<int> s;
set<int> result;
int a[3],full[3];


void dfs()
{
    int tmp = a[0] * 10000 + a[1] * 100 + a[2];
    if (s.find(tmp) != s.end())
    {
        return;
    }
    
    s.insert(tmp);
    if (a[0] == 0)
        result.insert(a[2]);
    
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] != 0)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i != j && a[j] < full[j])
                {
                    int minn = min(full[j] - a[j], a[i]);
                    a[i] -= minn;
                    a[j] += minn;
                    dfs();
                    a[i] += minn;
                    a[j] -= minn;
                }
            }
        }
    }
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    vector<int> v;
    
    fin >> full[0] >> full[1] >> full[2];
    a[2] = full[2];
    
    dfs();
    
    for (set<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        v.push_back(*it);
    }
    
    sort(v.begin(), v.end());
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            fout << " ";
        }
        fout << *it;
    }
    
    fout << "\n";
    
    return 0;
}
