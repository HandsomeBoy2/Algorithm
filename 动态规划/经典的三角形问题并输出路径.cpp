#include <stdio.h>
#include <iostream>
#include <algorithm> 
using namespace std;
int main() {
	int a[5][5] = {0};
	int b[5][5] = {0};  //b数组用来复制一下a数组 
	int i, j, t1, t2, max1 = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}
	} 
	for (i = 3; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			a[i][j] = a[i][j] + max(a[i+1][j], a[i+1][j+1]);
		}
	}
	printf("%d\n", a[0][0]); //输出最大值 
	printf("%d\t", b[0][0]); //输出第一个路径值 
	for (i = 1; i < 4; i++) { //找出每行的最大值，b数组用这个最大值所对应的坐标输出，输出的就是路径值 
		for (j = 0; j <= i; j++) {
			if (a[i][j] >= max1) {
				max1 = a[i][j];
				t1 = i;  //找出下标 
				t2 = j;
			}
		}
		max1 = 0;
		printf("%d\t", b[t1][t2]);
	}
	printf("%d\t", max(b[t1+1][t2], b[t1+1][t2+1])); //输出最后一个路径值 
 	return 0;
}

