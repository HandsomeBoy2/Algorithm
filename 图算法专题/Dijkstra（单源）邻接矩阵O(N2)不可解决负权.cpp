#include <stdio.h>
int main() {
	int i, j, k, m, n, v1, v2, w, min, u;
	int a[51][51], book[2501], dis[51];
	scanf("%d %d", &m, &n);
	//��ʼ��
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 999999;
		}
	}
	//�����
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		a[v1][v2] = w;
	}
	//��ʼ��dis����
	for (i = 1; i <= m; i++) {
		dis[i] = a[1][i];
	}
	//book�����ʼ��
	for (i = 1; i <= m; i++) {
		book[i] = 0;
	}
	book[1] = 1;
	//Dijkstra�㷨�������
	for (i = 1; i <= m - 1; i++) {
		//����1�Ŷ�������ĵ�
		min = 999999;
		for (j = 1; j <= m; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (k = 1; k <= m; k++) {
			if (a[u][k] < 999999) {
				if (dis[k] > dis[u] + a[u][k]) {
					dis[k] = dis[u] + a[u][k];
				}
			}
		}
	}
	//������յĽ��
	for (i = 2; i <= m; i++) {
		printf("%d\n", dis[i]);
	}

	getchar();
	getchar();
	return 0;
}

