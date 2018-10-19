#include <stdio.h>
using namespace std;
struct node 
{
	int x; //横坐标 
	int y; //纵坐标 
} ;

int main()
{
	struct node que[2501];
	int head, tail, sum;
	int a[51][51];
	int book[51][51] = {0};
	int i, j, m, n, startx, starty, tx, ty;
	scanf("%d %d %d %d", &m, &n, &startx, &starty); //m行n列以及小哼降落的位置坐标 
	for (i = 1; i <= m; i++) { //读入地图 
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int next[4][2] = {	{0, 1}, //方向数组 
						{1, 0},
						{0, -1},
						{-1, 0}};
	head = 1, tail = 1; //队列初始化 
	que[tail].x = startx;//往队列里插入降落的起始坐标 
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;
	while (head < tail) { //当队列不为空的时候循环 
		for (i = 0; i <= 3; i++) { //枚举4个方向 
			tx = que[tail].x + next[i][0]; //计算下一步的坐标 
			ty = que[tail].y + next[i][1];
			if (tx < 1 ||  ty < 1 || tx > m || ty > n) //判断是否越界 
				continue;
			if (a[tx][ty] > 0 && book[tx][ty] == 0) {	//判断是否是陆地或者曾经是否走过 
				sum++;
				book[tx][ty] = 1;  //每一个点只入队一次，所以需要标记这个点已经走过
				que[tail].x = tx; //将新扩展的点加入队列 
				que[tail].y = ty;
				tail++;
			}
 		}
		head++; //注意这个地方千万不要忘记 
				//当一个点扩展结束后，head++才能继续往下扩展 
	}
	printf("%d\n", sum); 
	
	getchar();
	getchar();
	return 0;
}

