#include<iostream>
#include<math.h> 
#include<time.h>
#include<string.h>
#include <algorithm>
using namespace std;
int main(){
	int ans[100005]={};
	for(int i=1;i<100005;i++){
		int x=i,y=i;
		while(x>0){
			y+=(x%10);
			x/=10;
		}
		if(ans[y]==0||i<ans[y])ans[y]=i;
	}
	int n;
	cin>>n;
	while(n--){
		int in;
		cin>>in;
		cout<<ans[in]<<endl;
	}
}
