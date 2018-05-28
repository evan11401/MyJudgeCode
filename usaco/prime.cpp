#include<iostream>
#include<algorithm>
#include <math.h>
using namespace std;

bool sieve[20000000];
 
void eratosthenes()
{
    int sqrt_20000000 = sqrt(20000000);
    sieve[0] = sieve[1] = true;
    for (int i=2; i<=sqrt_20000000; i++)
        if (!sieve[i])
            for (int k=(20000000-1)/i, j=i*k; k>=i; k--, j-=i)
                if (!sieve[k])
                    sieve[j] = true;
}

int main(){
//	int a = 14803;
//	eratosthenes();
//	for(int i=100;i<1000;i++){
//		if(a%i!=0) continue;
//		int j = a/i;
//		if(!sieve[i]&&!sieve[j])
//			cout <<i<<" "<<j<<endl;
//	}
	double a = 107;
	double aa = 88.55;
	double b = a+17;
	double bb = 90;
	cout<<(b*bb-a*aa)/17;
}
