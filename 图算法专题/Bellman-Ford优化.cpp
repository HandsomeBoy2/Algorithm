#include <stdio.h>
#define INF 999999
int main()
{
	int i , k, dis[10], m, n, u[10], v[10], w[10];
	int check = 0, flag = 0;  //��ǰ�����ɳ�  ��⸺Ȩ�� 
	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	for (i = 1; i <= m; i++) {
		dis[i] = INF;
	}
	dis[1] = 0;
	for (k = 1; k <= m - 1; k++) {  //Bellman-Ford�����㷨��� 
		for (i = 1; i <= n; i++) {
			if (dis[v[i]] > dis[u[i]] + w[i]) {
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}	
 		}
 		if (check == 0) 
 			break;
	}
	for (i = 1; i <= m; i++) {
		if (dis[v[i]] > dis[u[i]] + w[i]) 
			flag = 1;
	}
	if (flag == 1) printf("��ͼ�а�����Ȩ��·");
	else {
		for (i = 1; i <= m; i++) {
			printf("%10d", dis[i]);
		}		
	}
	 
	getchar();
	getchar();
	return 0;
}


