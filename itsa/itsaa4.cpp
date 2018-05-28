#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	
	while(n--){
		int a;
		cin >>a;
		int ans=0;
		for(int i=1;i<a-1;i++){
			for(int j=1;j<a-1;j++){
				if(i+j>a-1)break;
				ans+=(a-i-j)*(a-i-j);
			}
		}
		
		cout<<ans<<endl;
	}
}
