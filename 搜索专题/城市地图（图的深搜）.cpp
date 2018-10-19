#include <stdio.h>
int  i, j, m, n, v1, v2, w, min = 99999999;
int book[101], a[101][101];
void dfs(int cur, int dis) 
{
	if (dis > min) return;
	if (cur == m) {
		if (dis < min) min = dis;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (a[cur][i] != 999999 && book[i] == 0) {
			book[i] = 1;
			dfs(i, dis + a[cur][i]);
			book[i] = 0;
		}
	}
	return;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else if (i != j) a[i][j] = 999999;
		}
	}
	
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		a[v1][v2] = w;
	}
	book[1] = 1;
	dfs(1, 0);
	
	printf("%d", min);
	getchar();
	getchar(); 
	return 0;
}

