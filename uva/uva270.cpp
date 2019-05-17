#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
typedef struct pnode
{
	double x,y;
}point;
point  P[701];
double S[701];
 
int main()
{
	int  t;
	char buf[100];
	scanf("%d",&t);
	getchar();
	gets(buf);
	while (t --) {
		int count = 0;
		while (gets(buf) && buf[0]) {
			sscanf(buf, "%lf%lf", &P[count].x,&P[count].y);
			count ++;
		}
		
		int max = 0;
		for (int i = 0 ; i < count ; ++ i) {
			int save = 0;
			for (int j = 0 ; j < count ; ++ j) {
				if (j == i) continue;
				if (P[i].x == P[j].x)
					S[save ++] = 1e1000;
				else
					S[save ++] = (P[j].y-P[i].y)/(P[j].x-P[i].x);
			}
			sort(S, S+save);
			int now = 1;
			for (int j = 1 ; j < save ; ++ j)
				if (S[j] == S[j-1])
					now ++;
				else {
					if (max < now) max = now;
					now = 1;
				}
			if (max < now) max = now;
		}
		
		printf("%d\n",max+1);
		if (t) printf("\n");
	}
    return 0;
}

