#include<iostream>
#include<cstring>
#define LL long long 
using namespace std;
const int maxn =65005;
LL in;
int isprime[maxn];
void getPrime(){
	isprime[1]=1;
	memset(isprime,0,sizeof(isprime));
	for(int i=2;i*2<maxn;i++){			
		for(int j=i*i;j<maxn;j+=i){
			
			isprime[j]=1;
		}
	}
}
LL getPower(LL a,LL n){
	if(n==0)return 1;
	else{
		LL ret = getPower(a,n/2);
		ret = ret*ret;
		ret%=in;
		if(n%2==1)ret*=a;
		ret%=in;
		return ret;
	}
} 
int main(){
	getPrime();
	
	while(cin>>in&&in!=0){		
		int chk=1;
		if(isprime[in]==0)
			chk=0;
		else
			for(LL i=2;i<in;i++){
				
				if(getPower(i,in)%in!=i){
					chk=0;
					//cout<<i<<" "<<getPower(i,in)<<endl;
					break;
				}
			}
		if(chk==1){
			cout<<"The number "<<in<<" is a Carmichael number.\n";
		}else{
			cout<<in<<" is normal.\n";
		}
	}
}
