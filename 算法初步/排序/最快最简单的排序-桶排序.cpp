/*徐子峰大帅哥   哈哈哈哈哈*/
/*日期：2017-11-12*/

#include <iostream>

using namespace std;
int main()
{
	int a[11], i, j, t;
	for (i = 1; i <= 10; i++)     //初始化为0 
		a[i] = 0;
		
	for (i = 1; i <= 5; i++) { //循环读入5个数 
 		scanf("%d", &t);
		a[t]++;   //进行计数 
	}
	
	for (i = 1; i <= 10; i++)  //依次判断a[0]~a[10]  从小到大排序 
		for (j = 1; j <= a[i]; j++)
			printf("%d ", i);
			
	/*for (i = 10; i > 0; i++)  //依次判断a[10]~a[0]  从大到小排序 
		for (j = 1; j <= a[i]; j++)
			printf("%d ", i);
	*/

	getchar();
	getchar(); 
	return 0;
}
/* 
测试用例： 1 5 2 3 4 
测试结果： 1 2 3 4 5      
只能排1-10之间的  因为a数组只有11个 
*/ 

