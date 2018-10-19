/*徐子峰大帅哥   哈哈哈哈哈*/
/*日期：2017-11-12*/

#include <iostream>

using namespace std;
void InsertSort(int *a, int n)
{ 
	int i,j;
	for (i = 2; i <= n; i++)	{
		if (a[i] < a[i - 1]) {/* 需将a[i]插入 */
			a[0] = a[i]; /* 设置哨兵 */
			for(j = i - 1; a[j] > a[0];j--)
				a[j + 1] = a[j]; /* 记录后移 */
			a[j + 1] = a[0]; /* 插入到正确位置 */ 
		}
	}
}

int main()
{
	int i, j, a[11];
	for (i = 1; i <= 10; i++)   //初始化为0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) 	//读入10个数 
		scanf("%d", &a[i]); 
	
	InsertSort(a, 10);  		//直接插入排序 
	
	for (i = 1; i <= 10; i++) 	//输出排序后的10个数 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input:15 12 45 12 22 55 89 78 14 15
Output:12 12 14 15 15 22 45 55 78 89
*/
