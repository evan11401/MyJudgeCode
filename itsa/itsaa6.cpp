#include<iostream>
using namespace std;
int main(){
	int n;
	cin >>n;
	while(n--){
		int input,last;
		cin>>last;
		int num=2;
		int maxx = 0;
		if(last!=0)
			while(cin>>input&&input!=0){
				if(input>=last){
					num++;
				}else{
					maxx = max(num,maxx);
					num=2;
				}
				last = input;
			}
		maxx = max(num,maxx);
		cout<<maxx<<endl;
	}
}
