#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int dp[10010];//dp[i]��ʾ����Ϊi+1��������ĩβԪ����Сֵ��
int a[10010];
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			dp[i] = INF;//��������memset�����鸳ֵINF,ֻ�ܸ�ֵ0��-1��
						//������fill(dp,dp+n,INF);
		}
		for(int i = 0; i < n; i++) {
			*lower_bound(dp, dp+n, a[i]) = a[i]; //�ҵ�>=a[i]�ĵ�һ��Ԫ�أ�����a[i]�滻��
		}
		printf("%d\n", lower_bound(dp, dp+n, INF) - dp);//�ҵ���һ��INF�ĵ�ַ��ȥ�׵�ַ������������еĳ��ȣ�
	}
	return 0;
}
