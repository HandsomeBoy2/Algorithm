/*徐子峰大帅哥   哈哈哈哈哈*/
/*日期：2017-11-12*/

#include <iostream>

using namespace std;
int a[11];

void QuickSort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	
	temp = a[left];  //temp中存入基准数 
	i = left;
	j = right;
	while (i != j) {
	 	while (a[j] >= temp && i < j)  //顺序很重要 要先从右到左找 
			j--;
		while (a[i] <= temp && i < j) //再从左往右找 
			i++;
		if (i < j) { //当i与j不相等时，交换两个数 
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}	
	}
	a[left] = a[i];
	a[i] = temp;
	
	QuickSort(left, i - 1);
	QuickSort(i + 1, right);
	return;
}

int main()
{
	int i, j;
	for (i = 1; i <= 10; i++)     //初始化为0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) //读入10个数 
		scanf("%d", &a[i]); 
	
	QuickSort(1, 10);  //传入快排的数字左右位置 
	
	for (i = 1; i <= 10; i++) //输出排序后的10个数 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input:10 20 50 12 13 154 10 20 30 40
Output:10 10 12 13 20 20 30 40 50 154
*/
