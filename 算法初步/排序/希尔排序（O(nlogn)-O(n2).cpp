/*���ӷ��˧��   ����������*/
/*���ڣ�2017-11-12*/

#include <iostream>

using namespace std;
void ShellSort(int *a, int n) 
{
	int i, j;
	int increment = n;
	do {
		increment = increment / 3 + 1;/* �������� */
		for(i = increment + 1; i <= n; i++)	{
			if (a[i] < a[i - increment]) { /*  �轫a[i]�������� */ 
				a[0] = a[i]; /*  �ݴ���a[0] */
				for (j = i - increment; j > 0 && a[0] < a[j]; j -= increment)
					a[j + increment] = a[j]; /*  ��¼���ƣ����Ҳ���λ�� */
				a[j + increment] = a[0]; /*  ���� */
			}
		}
	} while (increment > 1);
}

int main()
{
	int i, j, a[11];
	for (i = 1; i <= 10; i++)   //��ʼ��Ϊ0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) 	//����10���� 
		scanf("%d", &a[i]); 
	
	ShellSort(a, 10);  		//ϣ������ 
	
	for (i = 1; i <= 10; i++) 	//���������10���� 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input:15 20 45 65 21 20 10 10 14 15
Output:10 10 14 15 15 20 20 21 45 65
*/
