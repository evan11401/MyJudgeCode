#include<iostream>
#include<math.h> 
#include<time.h>
#include<string.h>
#include <algorithm>
using namespace std;
int main(){
	string mirr="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	string msg[]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};
	string in;
	
	while(cin>>in){
		int msgi=2;
		bool mid_is_mi=1;
		if(in.length()&1){
			char min = in[in.length()/2];
			if(min=='A'||min=='H'||min=='I'||min=='O'||min=='T'||min=='M'||min=='U'||min=='V'||min=='W'||min=='X'||min=='Y'||min=='8'){
				mid_is_mi=1;
			}
			else {
				mid_is_mi=0;
				msgi=0;
			}
		}
		if(mid_is_mi)
			for(int i=0,j=in.length()-1;i<in.length()/2;i++,j--){
				char rev;
				if(in[i]-'A'>=0) rev = mirr[in[i]-'A'];
				else rev = mirr[25+in[i]-'0'];
//				cout<<in[i]<<" "<<rev<<endl;
				if(rev!=in[j]){
					
					msgi=0;
					break;
				}
			}
		
		string re = in;		
		reverse(re.begin(),re.end());
		if(in == re){
			msgi++;
		}
		cout<<in<<" -- "<<msg[msgi]<<endl<<endl;
	}

} 
