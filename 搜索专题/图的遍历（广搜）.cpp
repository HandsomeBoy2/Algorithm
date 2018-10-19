#include <stdio.h>
using namespace std;

int main()
{
	int i, j, m, n, v1, v2, cur, book[51] = {0}, a[51][51];
	int head, tail, que[2501];
	scanf("%d %d", &m, &n);	//����ͼ�Ķ�������ͱ���
	
	for (i = 1; i <= m; i++) {	//��ʼ����ά����
		for (j = 1; j <= m; j++) {
			if (i == j) a[i][j] = 0;
			else if (i != j) a[i][j] = 999999;
		}
	}
	
	for (i = 1; i <= n; i++) {	//����ͼ�ı���
		scanf("%d %d", &v1, &v2);
		a[v1][v2] = 1;
		a[v2][v1] = 1;	//��ͼΪ����ͼ 
	}
	
	head = 1, tail = 1;	//���г�ʼ�� 
	que[tail] = 1;   	//��1�Ŷ��������� 
	book[1] = 1;		//���1�Ŷ����ѷ��� 
	tail++;
	while (head < tail && tail <= m) {	//�����в�Ϊ�յ�ʱ��ѭ�� 
		cur = que[head];	  //��ǰ���ʵĶ����� 
		for (i = 1; i <= m; i++) {  //��1-m���γ��� 
			if (a[cur][i] == 1 && book[i] == 0) { //�ж�cur����Ͷ���i�Ƿ��бߣ����ж϶���i�Ƿ��Ѿ����ʹ� 
				que[tail] = i;
				book[i] = 1;
				tail++;
			}
			if (tail > m) {  //���tail����m����������ж��㶼�ѽ������ʹ� 
				break;
			}
		}
		head++; //ע����ط���ǧ��Ҫ���ǵ�һ��������չ������head++��Ȼ����ܼ���������չ 
	}
	
	for (i = 1; i < tail; i++) { //���������� 
		printf("%d ", que[i]);
	}
	
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
Output��1 2 3 5 4	 

*/
