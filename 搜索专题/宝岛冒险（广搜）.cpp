#include <stdio.h>
using namespace std;
struct node 
{
	int x; //������ 
	int y; //������ 
} ;

int main()
{
	struct node que[2501];
	int head, tail, sum;
	int a[51][51];
	int book[51][51] = {0};
	int i, j, m, n, startx, starty, tx, ty;
	scanf("%d %d %d %d", &m, &n, &startx, &starty); //m��n���Լ�С�߽����λ������ 
	for (i = 1; i <= m; i++) { //�����ͼ 
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int next[4][2] = {	{0, 1}, //�������� 
						{1, 0},
						{0, -1},
						{-1, 0}};
	head = 1, tail = 1; //���г�ʼ�� 
	que[tail].x = startx;//����������뽵�����ʼ���� 
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;
	while (head < tail) { //�����в�Ϊ�յ�ʱ��ѭ�� 
		for (i = 0; i <= 3; i++) { //ö��4������ 
			tx = que[tail].x + next[i][0]; //������һ�������� 
			ty = que[tail].y + next[i][1];
			if (tx < 1 ||  ty < 1 || tx > m || ty > n) //�ж��Ƿ�Խ�� 
				continue;
			if (a[tx][ty] > 0 && book[tx][ty] == 0) {	//�ж��Ƿ���½�ػ��������Ƿ��߹� 
				sum++;
				book[tx][ty] = 1;  //ÿһ����ֻ���һ�Σ�������Ҫ���������Ѿ��߹�
				que[tail].x = tx; //������չ�ĵ������� 
				que[tail].y = ty;
				tail++;
			}
 		}
		head++; //ע������ط�ǧ��Ҫ���� 
				//��һ������չ������head++���ܼ���������չ 
	}
	printf("%d\n", sum); 
	
	getchar();
	getchar();
	return 0;
}

