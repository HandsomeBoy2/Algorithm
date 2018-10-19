#include <stdio.h>
using namespace std;
int a[51][51];
int book[51][51]; 
int m, n, sum;
void dfs(int x, int y, int color)  //���color 
{
	int tx, ty;
	//��������
	int next[4][2] = {	{0, 1},  
						{1, 0},
						{0, -1},
						{-1, 0}};
	a[x][y] = color;  //����Ⱦɫ 
	//ö��4������
	for (int i = 0; i <= 3; i++) {  
		tx = x + next[i][0]; //������һ�������� 
		ty = y + next[i][1];
		//�ж��Ƿ�Խ��
		if (tx < 1 ||  ty < 1 || tx > m || ty > n)  
			continue;
		//�ж��Ƿ���½�ػ��������Ƿ��߹�
		if (a[tx][ty] > 0 && book[tx][ty] == 0) {	 
			sum++; 
			book[tx][ty] = 1;
			dfs(tx, ty, color); //��ʼ������һ���� 
		}
	}
	return;
}

int main()
{
	int i, j, num = 0;
	scanf("%d %d %d %d", &m, &n); //m��n��
	for (i = 1; i <= m; i++) { //�����ͼ 
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] > 0) {
				--num;
				book[i][j] = 1;
				dfs(i, j, num);
			}
		}
	} 
	
	for (i = 1; i <= m; i++) {//���Ⱦɫ��ĵ�ͼ 
		for (j = 1; j <= n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("��%d��С��\n", -num); 
	getchar();
	getchar();
	return 0;
}

