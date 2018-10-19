/*徐子峰大帅哥   哈哈哈哈哈*/
/*日期：2017-11-12*/

#include <stdio.h>

/* 对数组作改进冒泡算法 */
void BubbleSort(int *a, int n)
{ 
	int i, j, temp;
	bool flag = true;	/* flag用来作为标记 */
	for (i = 1; i <= n && flag; i++) {  /* 若flag为true说明有过数据交换，否则停止循环 */
		flag = false;		/* 初始为False */
		for (j = n; j > i; j--) {
			if (a[j] >= a[j - 1]) {
				temp = a[j]; 	
				a[j] = a[j - 1];	/* 交换a[j]与a[j+1]的值 */
				a[j - 1] = temp;
				flag = true;		/* 如果有数据交换，则flag为true */
			}
		}
	}
}

int main()
{
	int a[11], i, j;
	for (i = 1; i <= 10; i++)     //初始化为0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) //读入10个数 
		scanf("%d", &a[i]); 
	
	BubbleSort(a, 10);  //冒泡排序 
	
	for (i = 1; i <= 10; i++) //输出排序后的10个数 
		printf("%d ", a[i]); 

	return 0;
}
/*
Input： 1 5 2 4 5 63 2 2 15 10
Output：63 15 10 5 5 4 2 2 2 1
*/


