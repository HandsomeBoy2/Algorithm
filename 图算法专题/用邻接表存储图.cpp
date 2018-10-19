#include <stdio.h>

int main()
{
	int i, m, n, k;
	scanf("%d %d", &m ,&n);
	int u[7], v[7], w[7];
	int first[7], next[7];
	for (i = 1; i <= m; i++) {
		first[i] = -1;
 	}
 	for (i = 1; i <= n; i++) {
 		scanf("%d %d %d", &u[i], &v[i], &w[i]);
 		next[i] = first[u[i]];
	 	first[u[i]] = i;
	}
	for (i = 1; i <= m; i++) {
			k = first[i];
 		while (k != -1) {
 			printf("%d %d %d\n", u[k], v[k], w[k]);
 			k = next[k];
		}
	}
 
	return 0;
}

