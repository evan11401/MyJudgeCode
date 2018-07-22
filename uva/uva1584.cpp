#include<iostream>
#include<math.h> 
#include<time.h>
#include<string.h>
#include <algorithm>
using namespace std;
int main(){
	int n; 
	cin>>n;
	while(n--){
		string in;
		cin>>in;
		int min = 0;
		int num = in.length();
		for(int i=1;i<num;i++){
			for(int j=0;j<num;j++){
				if(in[(min+j)%num]!=in[(i+j)%num]){
					//cout<<min<<" "<<i<<endl;
					//cout<<in[(min+j)%num]<<" "<<in[(i+j)%num]<<endl;
					min = (in[(min+j)%num]<=in[(i+j)%num])?min:i;
					//cout<<min<<endl;
					break;
				}
			}
			
		} 
		//cout<<min<<endl;
		for(int i=0;i<num;i++)cout<<in[(min+i)%num];
		cout<<endl;
	}
}
