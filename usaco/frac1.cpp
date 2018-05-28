/*
ID: evan11401
TASK: frac1
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
struct point{
    int up,down;
    double dev;
};

vector<point> ans;

bool cmp(point a,point b){
    return a.dev<b.dev;
}
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int n;

int main (){
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
	fin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            bool find=false;
            if(gcd(i,j)==1){
                point q ;
                q.up = j;
                q.down = i;
                q.dev = (double)j/i;
                // fout<<i<<" "<<j<<"dev"<<q.dev<<endl;
                ans.push_back(q);
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++)
        fout<<ans[i].up<<"/"<<ans[i].down<<endl;
	
	return 0;
}
