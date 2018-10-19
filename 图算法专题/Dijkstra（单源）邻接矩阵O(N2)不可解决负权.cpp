#include <stdio.h>
int main() {
	int i, j, k, m, n, v1, v2, w, min, u;
	int a[51][51], book[2501], dis[51];
	scanf("%d %d", &m, &n);
	//初始化
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 999999;
		}
	}
	//读入边
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		a[v1][v2] = w;
	}
	//初始化dis数组
	for (i = 1; i <= m; i++) {
		dis[i] = a[1][i];
	}
	//book数组初始化
	for (i = 1; i <= m; i++) {
		book[i] = 0;
	}
	book[1] = 1;
	//Dijkstra算法核心语句
	for (i = 1; i <= m - 1; i++) {
		//找离1号顶点最近的点
		min = 999999;
		for (j = 1; j <= m; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (k = 1; k <= m; k++) {
			if (a[u][k] < 999999) {
				if (dis[k] > dis[u] + a[u][k]) {
					dis[k] = dis[u] + a[u][k];
				}
			}
		}
	}
	//输出最终的结果
	for (i = 2; i <= m; i++) {
		printf("%d\n", dis[i]);
	}

	getchar();
	getchar();
	return 0;
}

