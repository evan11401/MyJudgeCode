/*
ID: evan11401
TASK: castle
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int wall[60][60];
int marked[60][60];
int roomsi[25000];
int a,b,room_num=0;
ofstream fout ("castle.out");
ifstream fin ("castle.in");

bool find(int po,int wall){
	while(po--)
		wall/=2;

	return wall%2==1;
}

void fill_flood(int i,int j,int num){
	marked[i][j] = num;
	//fout<<i<<" "<<j<<endl;
	roomsi[num]++;
	if(j-1>0)
		if(!find(0,wall[i][j]))
			if(!marked[i][j-1])
				fill_flood(i,j-1,num);
	if(i-1>0)
		if(!find(1,wall[i][j]))
			if(!marked[i-1][j])
				fill_flood(i-1,j,num);
	if(j+1<=a)
		if(!find(2,wall[i][j]))
			if(!marked[i][j+1])
				fill_flood(i,j+1,num);
	if(i+1<=b)
		if(!find(3,wall[i][j]))
			if(!marked[i+1][j])
				fill_flood(i+1,j,num);
	return;
}

int maxi=1,maxj=1,maxxx=0;
char zz;

void findwall(int i,int j){
	if(j-1>0)
		if(find(0,wall[i][j])){
			if(marked[i][j]==marked[i][j-1]) return;
			else 
				if(roomsi[marked[i][j]]+roomsi[marked[i][j-1]]>maxxx){
					maxxx  = roomsi[marked[i][j]]+roomsi[marked[i][j-1]];
					maxi = i;
					maxj = j;
					zz = 'W';
				}
		}
			
	if(i-1>0)
		if(find(1,wall[i][j])){
			if(marked[i][j]==marked[i-1][j]) return;
			else 
				if(roomsi[marked[i][j]]+roomsi[marked[i-1][j]]>maxxx){
					maxxx  = roomsi[marked[i][j]]+roomsi[marked[i-1][j]];
					maxi = i;
					maxj = j;
					zz = 'N';
				}
		}
			
	if(j+1<=a)
		if(find(2,wall[i][j])){
			if(marked[i][j]==marked[i][j+1]) return;
			else 
				if(roomsi[marked[i][j]]+roomsi[marked[i][j+1]]>maxxx){
					maxxx  = roomsi[marked[i][j]]+roomsi[marked[i][j+1]];
					maxi = i;
					maxj = j;
					zz = 'E';
				}
		}
			
	if(i+1<=b)
		if(find(3,wall[i][j])){
			if(marked[i][j]==marked[i+1][j]) return;
			else 
				if(roomsi[marked[i][j]]+roomsi[marked[i+1][j]]>maxxx){
					maxxx  = roomsi[marked[i][j]]+roomsi[marked[i+1][j]];
					maxi = i;
					maxj = j;
					zz = 'S';
				}
		}
			
}

int main (){
	fin>>a>>b;
	for(int i=1;i<=b;i++)
		for(int j=1;j<=a;j++)
			fin>>wall[i][j];

	for(int i=1;i<=b;i++){
		for(int j=1;j<=a;j++){
			if(!marked[i][j]){
				fill_flood(i,j,++room_num);
				// fout<<endl;
			}
		}
	}
	int maxx=0;
	int num=0;
	for(int i=0;i<=2500;i++){
		if(roomsi[i]){
			num++;
			maxx = max(maxx,roomsi[i]);
		}
	}
	fout<<num<<endl;
	fout<<maxx<<endl;

	for(int j=1;j<=a;j++){
		for(int i=b;i>0;i--){
			findwall(i,j);
		}
		// fout<<endl;
	}
	// for(int j=1;j<=a;j++){
	// 	for(int i=1;i<=b;i++){
	// 		// findwall(i,j);
	// 		fout<<marked[i][j]<<" ";
	// 	}
	// 	fout<<endl;
	// }

	fout<<maxxx<<endl;
	fout<<maxi<<" "<<maxj<<" "<<zz<<endl;

	return 0;
}
