#include <stdio.h>
int f[1000] = {0}, m, n, k, sum = 0;

void init()
{
	int i;
	for (int i = 1; i <= m; i++) 
		f[i] = i;
	return;
}
int getf(int v)
{
	if (f[v] == v)
		return v;
	else {
		f[v] = getf(f[v]);
		return f[v];
	}
}
void merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2) {
		f[t2] = t1;
	}
	return;
}
int main()
{
	int i, x, y;
	scanf("%d %d", &m, &n);
	//初始化 
	init();
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	} 
	
	//最后扫描有多少个独立的团伙
	for (i = 1; i <= m; i++) {
		if (f[i] == i)
			sum++;
	}
	printf("%d", sum);
	
	getchar(); 
	getchar();
	return 0;
}

