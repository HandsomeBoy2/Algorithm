#include <stdio.h>
using namespace std;
int a[51][51];
int book[51][51]; 
int m, n, sum;
void dfs(int x, int y)
{
	int i, tx, ty;
	int next[4][2] = {	{0, 1}, //�������� 
						{1, 0},
						{0, -1},
						{-1, 0}};
	for (i = 0; i <= 3; i++) { //ö��4������ 
		tx = x + next[i][0]; //������һ�������� 
		ty = y + next[i][1];
		if (tx < 1 ||  ty < 1 || tx > m || ty > n) //�ж��Ƿ�Խ�� 
			continue;
		if (a[tx][ty] > 0 && book[tx][ty] == 0) {	//�ж��Ƿ���½�ػ��������Ƿ��߹� 
			sum++;
			book[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
	return;
}

int main()
{
	int i, j, startx, starty;
	scanf("%d %d %d %d", &m, &n, &startx, &starty); //m��n���Լ�С�߽����λ������ 
	for (i = 1; i <= m; i++) { //�����ͼ 
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	book[startx][starty] = 1;
	sum = 1;
	dfs(startx, starty);
	
	printf("%d\n", sum); 
	getchar();
	getchar();
	return 0;
}

//�������Ե�  �Ͳ����ظ���Ƶ��������� 
/*	10 10 6 8
	1 2 1 0 0 0 0 0 2 3
	3 0 2 0 1 2 1 0 1 2
	4 0 1 0 1 2 3 2 0 1
	3 2 0 0 0 1 2 4 0 0
	0 0 0 0 0 0 1 5 3 0
	0 1 2 1 0 1 5 4 3 0
	0 1 2 3 1 3 6 2 1 0
	0 0 3 4 8 9 7 5 0 0
	0 0 0 3 7 8 6 0 1 2
	0 0 0 0 0 0 0 0 1 0
*/
