#include <stdio.h>
using namespace std;
int a[51][51];
int book[51][51]; 
int m, n, sum;
void dfs(int x, int y, int color)  //���color 
{
	int tx, ty;
	int next[4][2] = {	{0, 1}, //�������� 
						{1, 0},
						{0, -1},
						{-1, 0}};
	a[x][y] = color;  //����Ⱦɫ 
	for (int i = 0; i <= 3; i++) { //ö��4������ 
		tx = x + next[i][0]; //������һ�������� 
		ty = y + next[i][1];
		if (tx < 1 ||  ty < 1 || tx > m || ty > n) //�ж��Ƿ�Խ�� 
			continue;
		if (a[tx][ty] > 0 && book[tx][ty] == 0) {	//�ж��Ƿ���½�ػ��������Ƿ��߹� 
			sum++;
			book[tx][ty] = 1;
			dfs(tx, ty, color); //��ʼ������һ���� 
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
	dfs(startx, starty, -1);
	
	printf("%d\n", sum); 
	for (i = 1; i <= m; i++) {//���Ⱦɫ��ĵ�ͼ 
		for (j = 1; j <= n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}

