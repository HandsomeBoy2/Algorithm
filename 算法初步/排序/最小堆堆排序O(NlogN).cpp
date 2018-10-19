#include <stdio.h>
int h[101];
int n;
void swap(int x, int y) //交换 
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return; 
}
void siftdown(int i) //向下调整 
{
	int flag = 0, t;
	while (flag == 0 && i * 2 <= n) {
		if (h[i] > h[i * 2]) {
			t = i * 2;
		} else {
			t = i;
		}
		if (i * 2 + 1 <= n) {
			if (h[t] > h[i * 2 + 1]) 
				t = i * 2 + 1;
		}
		if (i != t) {
			swap(t, i);
			i = t;
		} else {
			flag = 1;
		}
	}
	return;
}
void creat() //建堆 
{
	int i;
	for (i = n / 2; i >= 1; i--) {
		siftdown(i);
	}
	return;
}
int deletemax( ) //删除最大的元素 
{
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}
int main()
{
	int i, num;
	scanf("%d", &num);
	for (i = 1; i <= num; i++) 
		 scanf("%d", &h[i]); 
	n = num; 	 
		 
	creat();
	
	for (i = 1; i <= num; i++)
 		printf("%d  ", deletemax());	
	
	getchar();
	getchar();	
	return 0;
}
/*
Input:	5
      	1 5 2 3 4
Output:1  2  3  4  5
*/
