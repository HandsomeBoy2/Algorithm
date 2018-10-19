#include <stdio.h>
using namespace std;
int a[51][51], book[51][51];
int m, n, p, q, min = 99999;
void dfs(int x, int y, int step) 
{
	if (x == p && y == q) { //判断是否到达
		if (step < min) {
			min = step;
		}
		return;
	}
	int tx, ty;
	int next[4][2] = { 	{0, 1},   //方向数组 
						{1, 0}, 
						{0, -1},
						{-1, 0},
						}; 
	for (int i = 0; i <= 3; i++) { //四种走法 
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 1 || ty < 1 || tx > m || ty > n) {//判断是否越界 
			continue;
		} 
		if (a[tx][ty] == 0 && book[tx][ty] == 0) {//判断是否是障碍或者已走过 
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);  //开始尝试下一个点 
			book[tx][ty] = 0; //尝试结束，取消这个点的标记 
		}
	} 
	return;
}
int main()
{
	int startx, starty;
	scanf("%d %d", &m, &n);   //输入迷宫的行数和列数 
	for (int i = 1; i <= m; i++) { //初始化  用0表示平地  用1表示障碍物 
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]); 
		}
	}
	
	scanf("%d %d %d %d", &startx, &starty, &p, &q);  //输入小哼这个盖世英雄的所在方位
													 //并且输入小哈这个娇弱美女的所困方位 
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	printf("%d", min);   //输出解救的最短路径 
	getchar();
	getchar();
	return 0;
}
/*
Input: 	5 4
		0 0 1 0
		0 0 0 0
		0 0 1 0
		0 1 0 0
		0 0 0 1
		1 1 4 3	
Output:	7
*/
