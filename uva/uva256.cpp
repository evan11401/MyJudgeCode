#include<iostream>
using namespace std;
int main(){
	int num;
	while(cin>>num){
		int size=1;
		for(int i=0;i<num/2;i++) size*=10;
		for(int i=0;i<size;i++){
			int sqr = i*i;
			if((sqr/size)+(sqr%size)==i){
				switch(num){
					case 2:{
						printf("%02d\n",sqr);
						break;
					}
					case 4:{
						printf("%04d\n",sqr);
						break;
					}
					case 6:{
						printf("%06d\n",sqr);
						break;
					}
					case 8:{
						printf("%08d\n",sqr);
						break;
					}
				}
			}
		}
	}
}
