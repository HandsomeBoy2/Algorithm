#include <stdio.h>
using namespace std;
int a[51][51], book[51][51];
int m, n, flag = 0;

void dfs(int x, int y, int front) 
{
	//�ж��Ƿ񵽴��յ㣬��ע������y��������m+1����һ��Ϊʲô 
	//�����ж��Ƿ񵽴��յ�һ��Ҫ����Խ���ж�֮ǰ
	if (x == m && y == n + 1) {
		flag = 1;
		return; 
	}
	
	//�ж��Ƿ�Խ��
	if (x < 1 || y < 1 || x > m || y > n)  
		return;
		
	//�ж�����ܵ��Ƿ���·�����Ѿ�ʹ�ù� 
	if (book[x][y] == 1)
		return;
	book[x][y] = 1; //���ʹ�ù���ǰ����ܵ� 
	
	//��ǰˮ����ֱ�ܵ���� 
	if (a[x][y] >= 5 && a[x][y] <= 6) {
		if (front == 1) { //�� 
			dfs(x, y+1, 1);
		}
		if (front == 2) { //�� 
			dfs(x+1, y, 2);
		}
		if (front == 3) { //�� 
			dfs(x, y-1, 3);
		} 
		if (front == 4) {// �� 
			dfs(x-1, y, 4);	
		}
	} 
	 
	//��ǰˮ������ܵ���� 
	if (a[x][y] >= 1 && a[x][y] <= 4) {
		if (front == 1) { //�� 
			dfs(x+1, y, 2);
			dfs(x-1, y, 4);
		}
		if (front == 2) { //�� 
			dfs(x, y+1, 1);
			dfs(x, y-1, 3);
		}
		if (front == 3) { //�� 
			dfs(x-1, y, 4);
			dfs(x+1, y, 2);
		} 
		if (front == 4) {// �� 
			dfs(x, y+1, 1);	
			dfs(x, y-1, 3);
		}
	} 
	book[x][y] = 0; //ȡ����� 
	return ; 
}

int main()
{
	scanf("%d %d", &m, &n);//������Ϸ��ͼ���к���  
	for (int i = 1; i <= m; i++) {
		for (int j =1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	//�ӣ�1,1����ʼ��������ˮ����Ҳ��1
	dfs(1, 1, 1); 
	//�ж��Ƿ��ҵ������跽��
	if (flag == 0) {  
		printf("impossible");
	} else {
		printf("�ҵ������跽��"); 
	}
	
	getchar();
	getchar(); 
	return 0;
}

