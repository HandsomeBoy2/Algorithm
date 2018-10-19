#include <stdio.h>
using namespace std;

int main()
{
	int i, j, m, n, v1, v2, cur, book[51] = {0}, a[51][51];
	int head, tail, que[2501];
	scanf("%d %d", &m, &n);	//输入图的顶点个数和边数
	
	for (i = 1; i <= m; i++) {	//初始化二维矩阵
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else if (i != j) a[i][j] = 999999;
		}
	}
	
	for (i = 1; i <= n; i++) {	//读入图的边数
		scanf("%d %d", &v1, &v2);
		a[v1][v2] = 1;
		a[v2][v1] = 1;	//此图为无向图 
	}
	
	head = 1, tail = 1;	//队列初始化 
	que[tail] = 1;   	//将1号顶点加入队列 
	book[1] = 1;		//标记1号顶点已访问 
	tail++;
	while (head < tail && tail <= m) {	//当队列不为空的时候循环 
		cur = que[head];	  //当前访问的顶点编号 
		for (i = 1; i <= m; i++) {  //从1-m依次尝试 
			if (a[cur][i] == 1 && book[i] == 0) { //判断cur顶点和顶点i是否有边，并判断顶点i是否已经访问过 
				que[tail] = i;
				book[i] = 1;
				tail++;
			}
			if (tail > m) {  //如果tail大于m，则表明所有顶点都已将被访问过 
				break;
			}
		}
		head++; //注意这地方，千万不要忘记当一个顶点扩展结束后，head++，然后才能继续往下扩展 
	}
	
	for (i = 1; i < tail; i++) { //输出遍历结果 
		printf("%d ", que[i]);
	}
	
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
Output：1 2 3 5 4	 

*/
