#include<iostream>
using namespace std;
int power(int a, int n)//  power(a, n) ªí¥Ü¸ß°Ý a^n
{
	int ans=1;
	for(;n;n>>=1,a*=a){
        if(n&1) ans*=a;
    	cout<<n<<endl;
    	//cout<<a<<endl;
	}
	return ans;
} 
int main(){
	power(5,10);
	
} 
