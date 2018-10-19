#include <stdio.h>
#define INF 999999
int dis[7], book[7] = {0};//book数组用来记录哪些顶点已经放在生成树中 
int h[7], pos[7], size; //h用来保存堆，pos用来存储每个顶点在堆中的位置，size为堆的大小 

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	
	//同步更新pos
	t = pos[h[x]];
	pos[h[x]] = pos[h[y]];
	pos[h[y]] = t;
}

void siftdown(int i)
{
	int t, flag = 0; 
	while (i * 2 <= size && flag == 0) {
		if (dis[h[i]] > dis[h[i * 2]])
			t = i * 2;
		else 
		 	t = i;
		if (i * 2 + 1 <= size) {
			if (dis[h[t]] > dis[h[i * 2 + 1]])
				t = i * 2 + 1;
		}
		if (t != i) {
			swap(t, i);
			i = t;
		} else {
			flag = 1;			
		}
	}
	return;
}

void siftup(int i)
{
	int flag = 0;
	if (i == 0) return;
	while (i != 1 && flag == 0) {
		if (dis[h[i]] < dis[h[i / 2]])
			swap(i, i / 2);
		else
			flag = 1;
		i = i / 2;
	} 
	return;
}

int pop()
{
	int t;
	t = h[1];
	h[1] = h[size];
	pos[h[1]] = 1;
	size--;
	siftdown(1);
	return t;
} 
 
int main()
{
	int i, j, k, m, n;
	int u[19], v[19], w[19], first[17], next[19];
	int count = 0, sum = 0;
	//读入m和n 
	scanf("%d %d", &m, &n);
	//读入边
	for (i = 1; i <= n; i++) 
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	//这里是无向图，所以需要将所有的边再反向存储一次
	for (i = n + 1; i<= 2 * n; i++) {
		u[i] = v[i - n];
		v[i] = u[i - n];
		w[i] = w[i - n];
	}
	//开始使用邻接表存储边 
	for (i = 1; i <= m; i++) first[i] = -1; 
	
	for (i = 1; i <= 2 * n; i++) {
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	//Prim核心部分开始
	//将1号顶点加入生成树
	book[1] = 1;
	count++;
	
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始距离
	dis[1] = 0; 
	for (i = 2; i <= m; i++) dis[i] = INF;
	k = first[1];
	while (k != -1) {
		dis[v[k]] = w[k];
		k = next[k];
	}
	//初始化堆 
	size = m; 
	for (i = 1; i <= size; i++) {
		h[i] = i;
		pos[i] = i;
	}
	for (i = size / 2; i >= 1; i--) 
		siftdown(i);
	pop(); //先弹出一个堆顶元素 
	
	while (count < m) {
		j = pop();
		book[j] = 1; count++; sum+= dis[j]; 
		
		//扫描当前顶点j所有的边，再以j为中间结点，进行松弛 
		k = first[j];
		while (k != -1) {
			if (book[v[k]] == 0 && dis[v[k]] > w[k]) {
				dis[v[k]] = w[k];
				siftup(pos[v[k]]);
 			} 
 			k = next[k]; 
		}	
	}
	
	printf("%d", sum);
	
	getchar();getchar();
	return 0;
}

