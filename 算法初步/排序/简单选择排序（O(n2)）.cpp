/*���ӷ��˧��   ����������*/
/*���ڣ�2017-11-12*/

#include <iostream>

using namespace std;

void SelectSort(int *a, int n)
{
	int i, j, min, temp;
	for (i = 1; i <= n; i++) { 
		min = i;	 					/* ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i + 1; j <= n; j++) {	 /* ѭ��֮������� */
        	if (a[min] > a[j])	  		/* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;				/* ���˹ؼ��ֵ��±긳ֵ��min */
        }
		if (i != min) {					/* ��min������i��˵���ҵ���Сֵ������ */
			temp = a[i];			/* ����L->r[i]��L->r[min]��ֵ */
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

int main()
{
	int i, j, a[11];
	for (i = 1; i <= 10; i++)   //��ʼ��Ϊ0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) 	//����10���� 
		scanf("%d", &a[i]); 
	
	SelectSort(a, 10);  		//��ѡ������ 
	
	for (i = 1; i <= 10; i++) 	//���������10���� 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input��	1 5 2 3 4 5 6 8 9 10
Output��1 2 3 4 5 5 6 8 9 10
*/
