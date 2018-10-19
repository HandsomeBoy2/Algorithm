#include <stdio.h>
using namespace std;
int a[51][51], book[51][51];
int m, n, flag = 0;

void dfs(int x, int y, int front) 
{
	//判断是否到达终点，请注意这里y的坐标是m+1，想一想为什么 
	//另外判断是否到达终点一定要放在越界判断之前
	if (x == m && y == n + 1) {
		flag = 1;
		return; 
	}
	
	//判断是否越界
	if (x < 1 || y < 1 || x > m || y > n)  
		return;
		
	//判断这个管道是否在路径中已经使用过 
	if (book[x][y] == 1)
		return;
	book[x][y] = 1; //标记使用过当前这个管道 
	
	//当前水管是直管的情况 
	if (a[x][y] >= 5 && a[x][y] <= 6) {
		if (front == 1) { //左 
			dfs(x, y+1, 1);
		}
		if (front == 2) { //上 
			dfs(x+1, y, 2);
		}
		if (front == 3) { //右 
			dfs(x, y-1, 3);
		} 
		if (front == 4) {// 下 
			dfs(x-1, y, 4);	
		}
	} 
	 
	//当前水管是弯管的情况 
	if (a[x][y] >= 1 && a[x][y] <= 4) {
		if (front == 1) { //左 
			dfs(x+1, y, 2);
			dfs(x-1, y, 4);
		}
		if (front == 2) { //上 
			dfs(x, y+1, 1);
			dfs(x, y-1, 3);
		}
		if (front == 3) { //右 
			dfs(x-1, y, 4);
			dfs(x+1, y, 2);
		} 
		if (front == 4) {// 下 
			dfs(x, y+1, 1);	
			dfs(x, y-1, 3);
		}
	} 
	book[x][y] = 0; //取消标记 
	return ; 
}

int main()
{
	scanf("%d %d", &m, &n);//读入游戏地图的行和列  
	for (int i = 1; i <= m; i++) {
		for (int j =1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	//从（1,1）开始搜索，进水方向也是1
	dfs(1, 1, 1); 
	//判断是否找到了铺设方案
	if (flag == 0) {  
		printf("impossible");
	} else {
		printf("找到了铺设方案"); 
	}
	
	getchar();
	getchar(); 
	return 0;
}

