/*���ӷ��˧��   ����������*/
/*���ڣ�2017-11-12*/

#include <iostream>

using namespace std;
int a[11];

void QuickSort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	
	temp = a[left];  //temp�д����׼�� 
	i = left;
	j = right;
	while (i != j) {
	 	while (a[j] >= temp && i < j)  //˳�����Ҫ Ҫ�ȴ��ҵ����� 
			j--;
		while (a[i] <= temp && i < j) //�ٴ��������� 
			i++;
		if (i < j) { //��i��j�����ʱ������������ 
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
	for (i = 1; i <= 10; i++)     //��ʼ��Ϊ0 
		a[i] = 0;

	for (i = 1; i <= 10; i++) //����10���� 
		scanf("%d", &a[i]); 
	
	QuickSort(1, 10);  //������ŵ���������λ�� 
	
	for (i = 1; i <= 10; i++) //���������10���� 
		printf("%d ", a[i]); 
		
	getchar();
	getchar();	
	return 0;
}
/*
Input:10 20 50 12 13 154 10 20 30 40
Output:10 10 12 13 20 20 30 40 50 154
*/
