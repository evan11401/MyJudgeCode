#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string str1,str2;
	while(cin>>str1>>str2){
		
		string num1="",num2="";
		int a[26]={},b[26]={};	
		for(int i=0;i<str1.length();i++){
			a[str1[i]-'A']++;
			b[str2[i]-'A']++;
		}
		sort(a,a+26);
		sort(b,b+26);
		string s1="",s2="";
		for(int i=0;i<26;i++){
			s1+=a[i];
		}
		
		for(int i=0;i<26;i++){
			s2+=b[i];
		}
		
		if(s1==s2)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
