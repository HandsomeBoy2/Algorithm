/*���ӷ��˧��   ����������*/
/*���ڣ�2017-11-12*/

#include <stdio.h>

/* ���������Ľ�ð���㷨 */
void BubbleSort(int *a, int n)
{ 
	int i, j, temp;
	bool flag = true;	/* flag������Ϊ��� */
	for (i = 1; i <= n && flag; i++) {  /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
		flag = false;		/* ��ʼΪFalse */
		for (j = n; j > i; j--) {
			if (a[j] >= a[j - 1]) {
				temp = a[j]; 	
				a[j] = a[j - 1];	/* ����a[j]��a[j+1]��ֵ */
				a[j - 1] = temp;
				flag = true;		/* ��������ݽ�������flagΪtrue */
			}
		}
	}
}

int main()
{
	int a[11], i, j;
	for (i = 1; i <= 10; i++)     //��ʼ��Ϊ0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) //����10���� 
		scanf("%d", &a[i]); 
	
	BubbleSort(a, 10);  //ð������ 
	
	for (i = 1; i <= 10; i++) //���������10���� 
		printf("%d ", a[i]); 

	return 0;
}
/*
Input�� 1 5 2 4 5 63 2 2 15 10
Output��63 15 10 5 5 4 2 2 2 1
*/


