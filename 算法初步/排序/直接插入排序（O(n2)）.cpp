/*���ӷ��˧��   ����������*/
/*���ڣ�2017-11-12*/

#include <iostream>

using namespace std;
void InsertSort(int *a, int n)
{ 
	int i,j;
	for (i = 2; i <= n; i++)	{
		if (a[i] < a[i - 1]) {/* �轫a[i]���� */
			a[0] = a[i]; /* �����ڱ� */
			for(j = i - 1; a[j] > a[0];j--)
				a[j + 1] = a[j]; /* ��¼���� */
			a[j + 1] = a[0]; /* ���뵽��ȷλ�� */ 
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
	
	InsertSort(a, 10);  		//ֱ�Ӳ������� 
	
	for (i = 1; i <= 10; i++) 	//���������10���� 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input:15 12 45 12 22 55 89 78 14 15
Output:12 12 14 15 15 22 45 55 78 89
*/
