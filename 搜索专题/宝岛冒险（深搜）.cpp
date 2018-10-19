#include <stdio.h>
using namespace std;
int a[51][51];
int book[51][51]; 
int m, n, sum;
void dfs(int x, int y)
{
	int i, tx, ty;
	int next[4][2] = {	{0, 1}, //方向数组 
						{1, 0},
						{0, -1},
						{-1, 0}};
	for (i = 0; i <= 3; i++) { //枚举4个方向 
		tx = x + next[i][0]; //计算下一步的坐标 
		ty = y + next[i][1];
		if (tx < 1 ||  ty < 1 || tx > m || ty > n) //判断是否越界 
			continue;
		if (a[tx][ty] > 0 && book[tx][ty] == 0) {	//判断是否是陆地或者曾经是否走过 
			sum++;
			book[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
	return;
}

int main()
{
	int i, j, startx, starty;
	scanf("%d %d %d %d", &m, &n, &startx, &starty); //m行n列以及小哼降落的位置坐标 
	for (i = 1; i <= m; i++) { //读入地图 
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	book[startx][starty] = 1;
	sum = 1;
	dfs(startx, starty);
	
	printf("%d\n", sum); 
	getchar();
	getchar();
	return 0;
}

//用来测试的  就不用重复苦逼的再输入了 
/*	10 10 6 8
	1 2 1 0 0 0 0 0 2 3
	3 0 2 0 1 2 1 0 1 2
	4 0 1 0 1 2 3 2 0 1
	3 2 0 0 0 1 2 4 0 0
	0 0 0 0 0 0 1 5 3 0
	0 1 2 1 0 1 5 4 3 0
	0 1 2 3 1 3 6 2 1 0
	0 0 3 4 8 9 7 5 0 0
	0 0 0 3 7 8 6 0 1 2
	0 0 0 0 0 0 0 0 1 0
*/
