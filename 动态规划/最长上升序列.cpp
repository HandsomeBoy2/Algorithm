/*��״̬ת�Ʒ���Ϊ��
F[i]=MAX(F[1],��F[j]��,F[i-1]��������ѡ��һ���������F[i]������)+1
�±�Ϊj���ڵ�������С�ڵ���i���ڵ��� */ 
#include <iostream>
#include <algorithm>
#define Max 100 
using namespace std;
int main(){
	int n, a[Max], maxn, mark[Max] = {0};
	cin >> n;//Ҫ�������ֵĸ���
	int num[n];//ǰi���е�����½������еĳ��ȴ����num[i]��.
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		num[i] = 1;
		for(int j = 1; j <= i; j++){ //j��ʾi֮ǰ�����е��� 
			if(a[j]< a[i])//״̬����
			num[i] = max(num[j]+1, num[i]);
		}
		maxn = max(maxn, num[i]);
	}
//	 for(int i = 1; i <= n; i++){ �������������г��� 
//	 	if(max < num[i])
//	 		max = num[i];
//	 }
	 cout << maxn << endl;
	 return 0;
} 
