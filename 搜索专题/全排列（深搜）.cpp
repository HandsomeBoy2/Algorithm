#include <stdio.h>
int a[10], book[10], n; 
using namespace std;
void dfs(int step)
{
	int i;
	if (step == n + 1) {  //如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌 
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
			book[i] = 0;  //这是非常重要的一步，一定要将刚才尝试的扑克牌收回，才能进行下一次尝试 
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
