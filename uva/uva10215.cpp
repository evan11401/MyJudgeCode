#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	double l,w;
	while(cin>>l>>w){
		double maxx = ((l+w)-sqrt(l*l-l*w+w*w))/6;
		printf("%.3f ",maxx);
		printf("0.000 ");
		double minn = min(l/2,w/2);
		printf("%.3f\n",minn+(1E-8));
	}
}
