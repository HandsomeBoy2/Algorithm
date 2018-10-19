#include <stdio.h>
struct node {
	int x;
	int s;
};
int main() {
	struct node que[2501];
	int a[51][51], book[51];
	int i, j, m, n, v1, v2, begin, end, cur, flag = 0;
	int head, tail;
	scanf("%d %d %d %d", &m, &n ,&begin, &end);

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 999999;
		}
	}

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &v1, &v2);
		a[v1][v2] = 1;
		a[v2][v1] = 1;
	}

	head = 1;
	tail = 1;

	book[begin] = 1;
	que[tail].x = begin;
	que[tail].s = 0;
	tail++;
	while (head < tail) {
		cur = que[head].x;
		for (i = 1; i <= m; i++) {
			if (a[cur][i] != 999999 && book[i] == 0) {
				book[i] = 1;
				que[tail].x = i;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			if (que[tail - 1].x == end) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}


	if (flag == 1)
		printf("%d", que[tail - 1].s);
	getchar();
	getchar();
	return 0;
}

