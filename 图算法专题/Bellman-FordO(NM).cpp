#include <stdio.h>
#define INF 999999
int main()
{
	int i, k, dis[10], m, n, u[10], v[10], w[10];
	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	for (i = 1; i <= m; i++) {
		dis[i] = INF;
	}
	dis[1] = 0;
	for (k = 1; k <= m - 1; k++) {  //Bellman-FordºËÐÄËã·¨Óï¾ä 
		for (i = 1; i <= n; i++) {
			if (dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
 		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%10d", dis[i]);
	} 
	getchar();
	getchar();
	return 0;
}

