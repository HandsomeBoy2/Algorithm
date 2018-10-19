#include <stdio.h>
#define INF 999999
int main()
{
	int i, m, n, k, check, flag;
	int dis[10], book[10], u[10], v[10], w[10]; 
	int first[6], next[8];
	scanf("%d %d", &m, &n);
	
	for (i = 1; i <= m; i++) 
		dis[i] = INF;
	dis[1] = 0;
	
	for (i = 1; i <= m; i++) book[i] = 0;
	
	for (i = 1; i <= m; i++) first[i] = -1;
	
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]); 
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	
	int que[101] = {0}, head = 1, tail = 1;
	que[tail] = 1; tail++;
	book[1] = 1;
	while (head < tail) {
		k = first[que[head]];
		while (k != -1) {
			if (dis[v[k]] > dis[u[k]] + w[k]) 
				dis[v[k]] = dis[u[k]] + w[k];
			if (book[v[k]] == 0) {
				que[tail] = v[k];
				tail++;
				book[v[k]] = 1;
			}
			k = next[k];
		}
		book[que[head]] = 0;
		head++;
	}
	for (i = 1; i <= m; i++) 
		printf("%10d", dis[i]);
	getchar();
	getchar();
	return 0;
}

