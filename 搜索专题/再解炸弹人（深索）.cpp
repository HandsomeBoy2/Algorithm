#include <stdio.h>
using namespace std;

char a[20][21];  //�����洢��ͼ 
int book[20][20];
int head, tail;
int m, n, max, mx, my; 
int getsum(int i, int j)
{
	int sum, x, y;
	sum = 0; //sum����������������Ҫ��ʼ��Ϊ0
	x = i, y = j;  //���� 
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x--;
	} 
	x = i, y = j;  //���� 
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		x++;
	}
	
	x = i, y = j;  //���� 
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y--;
	}
	
	x = i, y = j;  //����	
	while (a[x][y] != '#') {
		if (a[x][y] == 'G')
			sum++;
		y++;	
	} 
	return sum;
}
void dfs(int x, int y) 
{
	int i, tx, ty, sum; 
	sum = getsum(x, y);
	if (sum > max) {
			max = sum;
			mx = x;
			my = y;
	}
	int next[4][2] = {         //�������� 
						{0, 1},
						{1, 0},
						{0, -1},
						{-1, 0},
					};	
	for (i = 0; i <= 3; i++) { //ö���ĸ����� 
			tx = x  + next[i][0];
			ty = y  + next[i][1];
			if (tx < 0 || ty < 0 || tx > m -1 || ty > n - 1) {
				continue;
			}
			if (a[tx][ty] == '.' && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				dfs(tx, ty);
				//book[tx][ty] = 0  //���Ѳ�һ���д˾�  �������� 
									//������п��ܳ�������һ�������ı��·����
									//Ҫ�������ó�δ����
			}
		} 
	return;
} 
int main()
{
	int i, startx, starty;  //���� 
	
	scanf("%d %d %d %d", &m, &n, &startx, &starty);
	for (i = 0; i < m; i++) 
			scanf("%s", a[i]);
	book[startx][starty] = 1;
	max = getsum(startx, starty);
	mx = startx;
	my = starty;
	dfs(startx, starty);
	
	printf("��ը�������ڣ�%d %d������ ��������%d������\n", mx, my, max);
	getchar();
	getchar();
	return 0;
}


