#include <stdio.h>
#include <iostream>
#include <algorithm> 
using namespace std;
int main() {
	int a[5][5] = {0};
	int b[5][5] = {0};  //b������������һ��a���� 
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
	printf("%d\n", a[0][0]); //������ֵ 
	printf("%d\t", b[0][0]); //�����һ��·��ֵ 
	for (i = 1; i < 4; i++) { //�ҳ�ÿ�е����ֵ��b������������ֵ����Ӧ���������������ľ���·��ֵ 
		for (j = 0; j <= i; j++) {
			if (a[i][j] >= max1) {
				max1 = a[i][j];
				t1 = i;  //�ҳ��±� 
				t2 = j;
			}
		}
		max1 = 0;
		printf("%d\t", b[t1][t2]);
	}
	printf("%d\t", max(b[t1+1][t2], b[t1+1][t2+1])); //������һ��·��ֵ 
 	return 0;
}

