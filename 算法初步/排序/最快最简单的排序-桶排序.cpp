/*���ӷ��˧��   ����������*/
/*���ڣ�2017-11-12*/

#include <iostream>

using namespace std;
int main()
{
	int a[11], i, j, t;
	for (i = 1; i <= 10; i++)     //��ʼ��Ϊ0 
		a[i] = 0;
		
	for (i = 1; i <= 5; i++) { //ѭ������5���� 
 		scanf("%d", &t);
		a[t]++;   //���м��� 
	}
	
	for (i = 1; i <= 10; i++)  //�����ж�a[0]~a[10]  ��С�������� 
		for (j = 1; j <= a[i]; j++)
			printf("%d ", i);
			
	/*for (i = 10; i > 0; i++)  //�����ж�a[10]~a[0]  �Ӵ�С���� 
		for (j = 1; j <= a[i]; j++)
			printf("%d ", i);
	*/

	getchar();
	getchar(); 
	return 0;
}
/* 
���������� 1 5 2 3 4 
���Խ���� 1 2 3 4 5      
ֻ����1-10֮���  ��Ϊa����ֻ��11�� 
*/ 

