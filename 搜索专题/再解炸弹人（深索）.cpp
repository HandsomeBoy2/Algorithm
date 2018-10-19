#include <stdio.h>
using namespace std;

char a[20][21];  //用来存储地图 
int book[20][20];
int head, tail;
int m, n, max, mx, my; 
int getsum(int i, int j)
{
	int sum, x, y;
	sum = 0; //sum用来记数，所以需要初始化为0
	x = i, y = j;  //向上 
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x--;
	} 
	x = i, y = j;  //向下 
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x++;
	}
	
	x = i, y = j;  //向左 
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y--;
	}
	
	x = i, y = j;  //向右	
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y++;	
	} 
	return sum;
}
void dfs(int x, int y) 
{
	int i, tx, ty, sum; 
	sum = getsum(x, y);
	if (sum > max) {
			max = sum;
			mx = x;
			my = y;
	}
	int next[4][2] = {         //方向数组 
						{0, 1},
						{1, 0},
						{0, -1},
						{-1, 0},
					};	
	for (i = 0; i <= 3; i++) { //枚举四个方向 
			tx = x  + next[i][0];
			ty = y  + next[i][1];
			if (tx < 0 || ty < 0 || tx > m -1 || ty > n - 1) {
				continue;
			}
			if (a[tx][ty] == '.' && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				dfs(tx, ty);
				//book[tx][ty] = 0  //深搜不一定有此句  根据需求定 
									//如果它有可能出现在下一次搜索的别的路径中
									//要重新设置成未访问
			}
		} 
	return;
} 
int main()
{
	int i, startx, starty;  //输入 
	
	scanf("%d %d %d %d", &m, &n, &startx, &starty);
	for (i = 0; i < m; i++) 
			scanf("%s", a[i]);
	book[startx][starty] = 1;
	max = getsum(startx, starty);
	mx = startx;
	my = starty;
	dfs(startx, starty);
	
	printf("将炸弹放置在（%d %d）处， 可以消灭%d个敌人\n", mx, my, max);
	getchar();
	getchar();
	return 0;
}


