#include <stdio.h>
using namespace std;
struct node 
{
	int x;
	int y;
};
char a[20][21];  //用来存储地图 

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

int main()
{
	struct node que[401];
	int book[20][20];
	int head, tail;
	int i, m, n, max;
	int startx, starty, mx, my, tx, ty, sum;  //输入 
	int next[4][2] = {         //方向数组 
						{0, 1},
						{1, 0},
						{0, -1},
						{-1, 0},
					};
	scanf("%d %d %d %d", &m, &n, &startx, &starty);
	for (i = 0; i < m; i++) 
			scanf("%s", a[i]);
	head = 1, tail = 1;//队列初始化 
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getsum(startx, starty);
	mx = startx;
	my = starty;
	while (head < tail) {
		for (i = 0; i <= 3; i++) { //枚举四个方向 
			tx = que[head].x  + next[i][0];
			ty = que[head].y  + next[i][1];
			if (tx < 0 || ty < 0 || tx > m-1 || ty > n-1) {
				continue;
			}
			if (a[tx][ty] == '.' && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
				sum = getsum(tx, ty);
				if (sum > max) {
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		head++;
	}
	
	printf("将炸弹放置在（%d %d）处， 可以消灭%d个敌人\n", mx, my, max);
	getchar();
	getchar();
	return 0;
}

