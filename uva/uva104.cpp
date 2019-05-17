#include <cstring>
#include <cstdio>
 
double value[25][25][25];
int    front[25][25][25];
 
void output(int t, int u, int v)
{
	if (t >= 1) {
		output(t-1, u, front[t][u][v]);
		printf(" %d", v);
	}else {
		printf("%d", u);
	}
}
 
int dp(int n)
{
	for (int t = 2; t <= n; ++ t) {
		for (int u = 1; u <= n; ++ u) {
			for (int v = 1; v <= n; ++ v) { 
				value[t][u][v] = -1.0;
				for (int k = 1; k <= n; ++ k) {
					if (value[t][u][v] < value[t-1][u][k]*value[1][k][v]) {
						value[t][u][v] = value[t-1][u][k]*value[1][k][v];
						front[t][u][v] = k;
					}
				}
			}
			if (value[t][u][u] > 1.01) { 
				output(t, u, u);
				printf("\n");
				return true;
			}
		}
	} 
	return false;
}
 
int main()
{
	int n;
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; ++ i) { 
			for (int j = 1; j <= n; ++ j) {
				if (i == j) {
					value[1][i][j] = 1.0;
				}else {
					scanf("%lf",&value[1][i][j]);
				}
			}
		} 
	
		if (!dp(n)) {
			printf("no arbitrage sequence exists\n");
		}
	}
    return 0;
}

