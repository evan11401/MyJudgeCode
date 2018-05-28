#include<iostream>
#include<math.h>
using namespace std;
typedef  long long ll;
const int maxn = 20000001;
ll ans[maxn];
int main(){
	
	for(int i=2;i<maxn;i++){
		for(int j=i;j<maxn;j+=i){
			ans[j]+=i;
		}
		ans[i]++;
		ans[i]+=ans[i-1];
	}
	int a;
	while(cin>>a&&a!=-0){
		
		cout<<ans[a]<<endl;
	}
}
