#include <stdio.h>
using namespace std;
int a[51][51], book[51];
int m, n, sum = 0;
void dfs(int cur) {
	printf("%d ", cur);
	sum++;    			//每访问一个顶点，sum就加1

	if (sum == m) return; //所有顶点访问过就退出

	for (int i = 1; i <= m; i++) { //从1号顶点到m号顶点一次尝试，看哪些顶点与当前顶点cur有边相连
		if (a[cur][i] == 1 && book[i] == 0) { //判断是否有边，并且是否顶点i已访问过
			book[i] = 1;   //标记i已访问过
			dfs(i);  //从顶点i再出发继续遍历
		}
	}
	return;
}

int main() {
	int i, j, v1, v2;
	scanf("%d %d", &m, &n);  //输入图的顶点个数和边数
	for (i = 1; i <= m; i++) { //初始化二维矩阵
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else if (i != j)  a[i][j] = 999999;
		}
	}
	for (i = 1; i <= n; i++) { //读入图的边数
		scanf("%d %d", &v1, &v2);
		a[v1][v2] = 1;
		a[v2][v1] = 1;   //此图为无向图
	}
	book[1] = 1; //标记1号顶点已访问
	dfs(1); //从1号顶点开始访问

	getchar();
	getchar();
	return 0;
}
/*
Input： 5 5
		1 2
		1 3
		1 5
		2 4
		3 5
Output：1 2 4 3 5

*/
