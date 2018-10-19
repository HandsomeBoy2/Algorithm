#include <stdio.h>
struct edge
{
	int u;
	int v;
	int w;
};
struct edge e[10];
int m, n;
int f[7] = {0}, sum = 0, count = 0;

void quicksort(int left, int right)
{
	int i, j;
	struct edge t;
	if (left > right)
		return;
	
	i = left;
	j = right;
	while (i != j) {
		while (e[j].w >= e[left].w && i < j)
			j--;
		while (e[i].w <= e[left].w && i < j)
			i++;
			
		if (i < j) {
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	
	quicksort(left, i - 1);
	quicksort(i + 1, right);
	return;
}

int getf(int x)
{
	if (f[x] == x)
		return x;
	else 
		return getf(f[x]);
}

int merge(int x, int y)
{
	int a, b;
	a = getf(x);
	b = getf(y);
	if (a != b) {
		f[b] = a;
		return 1;
	}
	return 0;
}

int main()
{
	int i;
	
	scanf("%d %d", &m, &n);
	
	for (i = 1; i <= n; i++)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		
	quicksort(1, n);
	
	for (i = 1; i <= m; i++)
		f[i] = i;
	
	for (i = 1; i <= n; i++) {
		if (merge(e[i].u, e[i].v)) {
			count++;
			sum = sum + e[i].w;
		}
		if (count == m - 1)
			break;
	}
	
	printf("%d", sum);
	getchar();
	getchar();
	return 0;
}

