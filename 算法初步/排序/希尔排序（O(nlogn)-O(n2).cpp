/*徐子峰大帅哥   哈哈哈哈哈*/
/*日期：2017-11-12*/

#include <iostream>

using namespace std;
void ShellSort(int *a, int n) 
{
	int i, j;
	int increment = n;
	do {
		increment = increment / 3 + 1;/* 增量序列 */
		for(i = increment + 1; i <= n; i++)	{
			if (a[i] < a[i - increment]) { /*  需将a[i]插入数组 */ 
				a[0] = a[i]; /*  暂存在a[0] */
				for (j = i - increment; j > 0 && a[0] < a[j]; j -= increment)
					a[j + increment] = a[j]; /*  记录后移，查找插入位置 */
				a[j + increment] = a[0]; /*  插入 */
			}
		}
	} while (increment > 1);
}

int main()
{
	int i, j, a[11];
	for (i = 1; i <= 10; i++)   //初始化为0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) 	//读入10个数 
		scanf("%d", &a[i]); 
	
	ShellSort(a, 10);  		//希尔排序 
	
	for (i = 1; i <= 10; i++) 	//输出排序后的10个数 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input:15 20 45 65 21 20 10 10 14 15
Output:10 10 14 15 15 20 20 21 45 65
*/
