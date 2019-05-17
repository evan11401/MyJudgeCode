#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
using namespace std;

int main(){
	set<string> S;
	string line, s1, s2;
    while(cin >> line)
        S.insert(line);
    for(set<string>::iterator i = S.begin(); i != S.end(); i++) {
        int len = (*i).length();
        for(int j = 0; j < len-1; j++) {
            s1 = (*i).substr(0, j+1);
            s2 = (*i).substr(j+1, len);
            //cout<<s1<<" "<<s2<<endl;
            if(S.find(s1) != S.end() && S.find(s2) != S.end()) {
                cout << (*i) << endl;
                break;
            }
        }
    }
}
