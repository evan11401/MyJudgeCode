#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define EPS 1E-6
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		double sum=0;
		double std[1005]={};
		for(int i=0;i<n;i++){
			cin>>std[i];
			sum+=std[i];
		}
		double avg = sum/n;
		double def1 = 0;
		double def2 = 0;
		for(int i=0;i<n;i++){
			if(std[i]>avg){
				def1+=floor((std[i]-avg)*100);
			}
			else{
				def2+=floor((avg-std[i])*100);
			}
		}
		if(def1>def2)
			printf("$%.2lf\n",def1/100+EPS);	
		else 
			printf("$%.2lf\n",def2/100+EPS);
	}
}
