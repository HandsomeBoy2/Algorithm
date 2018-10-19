#include <stdio.h>
using namespace std;
int a[51][51], book[51];
int m, n, sum = 0;
void dfs(int cur) {
	printf("%d ", cur);
	sum++;    			//ÿ����һ�����㣬sum�ͼ�1

	if (sum == m) return; //���ж�����ʹ����˳�

	for (int i = 1; i <= m; i++) { //��1�Ŷ��㵽m�Ŷ���һ�γ��ԣ�����Щ�����뵱ǰ����cur�б�����
		if (a[cur][i] == 1 && book[i] == 0) { //�ж��Ƿ��бߣ������Ƿ񶥵�i�ѷ��ʹ�
			book[i] = 1;   //���i�ѷ��ʹ�
			dfs(i);  //�Ӷ���i�ٳ�����������
		}
	}
	return;
}

int main() {
	int i, j, v1, v2;
	scanf("%d %d", &m, &n);  //����ͼ�Ķ�������ͱ���
	for (i = 1; i <= m; i++) { //��ʼ����ά����
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else if (i != j)  a[i][j] = 999999;
		}
	}
	for (i = 1; i <= n; i++) { //����ͼ�ı���
		scanf("%d %d", &v1, &v2);
		a[v1][v2] = 1;
		a[v2][v1] = 1;   //��ͼΪ����ͼ
	}
	book[1] = 1; //���1�Ŷ����ѷ���
	dfs(1); //��1�Ŷ��㿪ʼ����

	getchar();
	getchar();
	return 0;
}
/*
Input�� 5 5
		1 2
		1 3
		1 5
		2 4
		3 5
Output��1 2 4 3 5

*/
