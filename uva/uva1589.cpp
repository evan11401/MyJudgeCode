#include<iostream>
#define eps 1e-3
using namespace std;
int main(){
	double f;
	for(f=2;f>1;f-= 1e-6);
	f+=eps;
	printf("%.7f\n",f);
	printf("%.7f\n",f/4);
	printf("%.1f\n",f/4);
}
