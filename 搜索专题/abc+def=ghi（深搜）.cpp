#include <stdio.h>
using namespace std;

int a[10], book[10], total = 0, n; 
void dfs(int step)
{
	int i;
	if (step == n + 1) {  //���վ�ڵ�n+1��������ǰ�����ʾǰn�������Ѿ��ź��˿��� 
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] 
			== a[7] * 100 + a[8] * 10 + a[9]) {
			 total++; 
			printf("%d%d%d+%d%d%d=%d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
		} 
	return;
	}
	for (i = 1; i <= n; i++) {
		if (book[i] == 0) {
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int main()
{
	scanf("%d", &n); //������������ 
	dfs(1); //վ�ڵ�һ��������ǰ 
	
	printf("%d", total / 2);
	getchar();
	getchar();
	return 0;
}

