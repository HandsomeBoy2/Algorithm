#include <stdio.h>
#define INF 999999
int main()
{
	int i, j , k, m, n, v1, v2, w, temp, min;
	int a[7][7], dis[7], book[7] = {0};
	int count = 0, sum = 0;
	
	scanf("%d %d", &m, &n);
	
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			if (i == j ) a[i][j] = 0;
			else a[i][j] = INF; 
		}
	}
	
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		a[v1][v2] = w;
		a[v2][v1] = w;
	} 
	
	for (i = 1; i <= m; i++)
		dis[i] = a[1][i];
	
	//Prim核心算法部分 
	//将1号顶点加入生成树
	book[1] = 1;
	count++; 
	while (count < m) {
		min = INF;
		for (i = 1; i <= m; i++) {
			if (book[i] == 0 && dis[i] < min) {
				min = dis[i];
				temp = i;
			}
		}
		
		book[temp] = 1; 
		count++;
		sum += dis[temp];
		
		//扫描当前顶点j所有的边，再以j为中间点，更新生成树到每一个非树顶点的距离
		for (k = 1; k <= m; k++) {
			if (book[k] == 0 && dis[k] > a[temp][k])
				dis[k] = a[temp][k];
		} 
	}
	
	printf("%d", sum);
	
	getchar();
	getchar();
	return 0;
}

