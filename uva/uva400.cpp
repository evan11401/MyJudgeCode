#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int maxn=0;
		vector<string> names;
		string in;
		for(int i=0;i<n;i++){
			cin>>in;
			int inlen=in.length();
			maxn = max(maxn,inlen);
			names.push_back(in);
		}
		cout<<"------------------------------------------------------------\n";
		sort(ALL(names));
		int len=0,n_num;
		n_num = (60-maxn)/(maxn+2)+1;
		if(maxn>30) n_num=1;
		int row_num = n/n_num;
		int nn = row_num;
		//cout<<row_num<<" "<<n_num<<endl;
		if(n%n_num!=0)nn++;
		
		for(int i=0;i<nn;i++){
			for(int j=0;j<n_num;j++){
				if(i+j*nn>=n)break;
				if(j==n_num-1)
					printf("%*s",-maxn,names[i+j*nn].c_str());
				else
					printf("%*s",-maxn-2,names[i+j*nn].c_str());
			}
			cout<<endl;
		}
		
		
	}
}
