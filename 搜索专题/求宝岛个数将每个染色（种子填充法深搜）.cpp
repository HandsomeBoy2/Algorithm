#include <stdio.h>
using namespace std;
int a[51][51];
int book[51][51]; 
int m, n, sum;
void dfs(int x, int y, int color)  //添加color 
{
	int tx, ty;
	//方向数组
	int next[4][2] = {	{0, 1},  
						{1, 0},
						{0, -1},
						{-1, 0}};
	a[x][y] = color;  //将其染色 
	//枚举4个方向
	for (int i = 0; i <= 3; i++) {  
		tx = x + next[i][0]; //计算下一步的坐标 
		ty = y + next[i][1];
		//判断是否越界
		if (tx < 1 ||  ty < 1 || tx > m || ty > n)  
			continue;
		//判断是否是陆地或者曾经是否走过
		if (a[tx][ty] > 0 && book[tx][ty] == 0) {	 
			sum++; 
			book[tx][ty] = 1;
			dfs(tx, ty, color); //开始尝试下一个点 
		}
	}
	return;
}

int main()
{
	int i, j, num = 0;
	scanf("%d %d %d %d", &m, &n); //m行n列
	for (i = 1; i <= m; i++) { //读入地图 
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] > 0) {
				--num;
				book[i][j] = 1;
				dfs(i, j, num);
			}
		}
	} 
	
	for (i = 1; i <= m; i++) {//输出染色后的地图 
		for (j = 1; j <= n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("有%d个小岛\n", -num); 
	getchar();
	getchar();
	return 0;
}

