#include <stdio.h>
int a[10], book[10], n; 
using namespace std;
void dfs(int step)
{
	int i;
	if (step == n + 1) {  //���վ�ڵ�n+1��������ǰ�����ʾǰn�������Ѿ��ź��˿��� 
		for (i = 1; i <= n; i++) 
			printf("%d", a[i]);
		printf("\n");
		return;
	}
	for (i = 1; i <= n; i++) {
		if (book[i] == 0) {
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;  //���Ƿǳ���Ҫ��һ����һ��Ҫ���ղų��Ե��˿����ջأ����ܽ�����һ�γ��� 
		}	
	}
	return;
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	
	getchar();
	getchar();
	return 0;
}
/*
Input:	3
Output:	123
		132
		213
		312
		321
*/
