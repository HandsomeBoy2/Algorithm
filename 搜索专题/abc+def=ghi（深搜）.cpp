#include <stdio.h>
using namespace std;

int a[10], book[10], total = 0, n; 
void dfs(int step)
{
	int i;
	if (step == n + 1) {  //如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌 
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
	scanf("%d", &n); //输入最大的数字 
	dfs(1); //站在第一个盒子面前 
	
	printf("%d", total / 2);
	getchar();
	getchar();
	return 0;
}

