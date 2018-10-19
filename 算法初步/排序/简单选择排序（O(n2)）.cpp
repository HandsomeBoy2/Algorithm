/*徐子峰大帅哥   哈哈哈哈哈*/
/*日期：2017-11-12*/

#include <iostream>

using namespace std;

void SelectSort(int *a, int n)
{
	int i, j, min, temp;
	for (i = 1; i <= n; i++) { 
		min = i;	 					/* 将当前下标定义为最小值下标 */
		for (j = i + 1; j <= n; j++) {	 /* 循环之后的数据 */
        	if (a[min] > a[j])	  		/* 如果有小于当前最小值的关键字 */
                min = j;				/* 将此关键字的下标赋值给min */
        }
		if (i != min) {					/* 若min不等于i，说明找到最小值，交换 */
			temp = a[i];			/* 交换L->r[i]与L->r[min]的值 */
			a[i] = a[min];
			a[min] = temp;
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
	
	SelectSort(a, 10);  		//简单选择排序 
	
	for (i = 1; i <= 10; i++) 	//输出排序后的10个数 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input：	1 5 2 3 4 5 6 8 9 10
Output：1 2 3 4 5 5 6 8 9 10
*/
