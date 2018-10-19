#include <stdio.h>
using namespace std;
int a[51][51], book[51][51];
int m, n, p, q, min = 99999;
void dfs(int x, int y, int step) 
{
	if (x == p && y == q) { //�ж��Ƿ񵽴�
		if (step < min) {
			min = step;
		}
		return;
	}
	int tx, ty;
	int next[4][2] = { 	{0, 1},   //�������� 
						{1, 0}, 
						{0, -1},
						{-1, 0},
						}; 
	for (int i = 0; i <= 3; i++) { //�����߷� 
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 1 || ty < 1 || tx > m || ty > n) {//�ж��Ƿ�Խ�� 
			continue;
		} 
		if (a[tx][ty] == 0 && book[tx][ty] == 0) {//�ж��Ƿ����ϰ��������߹� 
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);  //��ʼ������һ���� 
			book[tx][ty] = 0; //���Խ�����ȡ�������ı�� 
		}
	} 
	return;
}
int main()
{
	int startx, starty;
	scanf("%d %d", &m, &n);   //�����Թ������������� 
	for (int i = 1; i <= m; i++) { //��ʼ��  ��0��ʾƽ��  ��1��ʾ�ϰ��� 
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]); 
		}
	}
	
	scanf("%d %d %d %d", &startx, &starty, &p, &q);  //����С���������Ӣ�۵����ڷ�λ
													 //��������С�����������Ů��������λ 
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	printf("%d", min);   //�����ȵ����·�� 
	getchar();
	getchar();
	return 0;
}
/*
Input: 	5 4
		0 0 1 0
		0 0 0 0
		0 0 1 0
		0 1 0 0
		0 0 0 1
		1 1 4 3	
Output:	7
*/
