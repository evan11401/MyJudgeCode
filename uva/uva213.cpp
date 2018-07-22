#include<iostream>
#include<string>
using namespace std;
int readchar(){
	while(1){
		int ch=getchar();
		if(ch!='\n'&&ch!='\r')return ch;
	}
}
int getnum(int c){
	int a=0;
	while(c--){
		a=a*2+readchar()-'0';
	}
	return a;
}

int main(){
	string in;
	while(getline(cin,in)){
		
		char code[10][1<<9]={};
		int ind=1;
		code[1][0]=in[0];
		for(int len=2;len<=7&&ind<in.length();len++){
			//cout<<(1<<len);
			for(int i=0;i<(1<<len)-1&&ind<in.length();i++){
				code[len][i]=in[ind++];
			}
		}
//		for(int len=1;len<=7;len++){
//			for(int i=0;i<(1<<len)-1;i++){
//				cout<<code[len][i]<<" ";
//			}
//			cout<<endl;
//		}
		
		while(1){
			int len=getnum(3);
			if(len==0)break;
			//cout<<"len"<<len<<endl;
			while(1){
				int read=getnum(len);
				
				//cout<<read<<endl;
				if(read==(1<<len)-1)break;
				else{
					cout<<code[len][read];
				}
			}
		}
		cout<<endl;
		getchar();
	}
	
} 

