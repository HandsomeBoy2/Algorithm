#include <stdio.h>
using namespace std;
struct node 
{
	int x;
	int y;
	int f;
	int s;
};

int main()
{
	struct node que[2501];
	int a[51][51], book[51][51];
	int head, tail;
	int m, n, p, q;
	scanf("%d %d", &m ,&n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int startx, starty, tx, ty;
	int next[4][2] = {	{0, 1},   //�������� 
						{1, 0},
						{0, -1},
						{-1, 0},
					}; 
	scanf("%d %d %d %d", &startx, &starty, &p, &q);
	head = 1, tail = 1; //���г�ʼ�� 
	que[tail].x = startx; 
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1; 
	int flag = 0;  //��������Ƿ񵽴�Ŀ��� 
	while(head < tail) {
		for (int i = 0; i <= 3; i++) {
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];
			if (tx < 1 || ty < 1 || tx > m || ty > n) {  //�ж��Ƿ�Խ�� 
				continue; 
			}
			if (a[tx][ty] == 0 && book[tx][ty] == 0) { 
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			} 
			if (tx == p && ty == q) {
				flag = 1; 
				break;
			}
		}	
		if (flag == 1) 
			break;
		head++; //ע������ط�ǧ��Ҫ���ǣ���һ������չ�����󣬲��ܶԺ���ĵ��ٽ�����չ	
	}
	printf("%d", que[tail - 1].s); 
	
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
