#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int dp[10010];//dp[i]表示长度为i+1的子序列末尾元素最小值；
int a[10010];
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			dp[i] = INF;//不可以用memset对数组赋值INF,只能赋值0或-1；
						//可以用fill(dp,dp+n,INF);
		}
		for(int i = 0; i < n; i++) {
			*lower_bound(dp, dp+n, a[i]) = a[i]; //找到>=a[i]的第一个元素，并用a[i]替换；
		}
		printf("%d\n", lower_bound(dp, dp+n, INF) - dp);//找到第一个INF的地址减去首地址就是最大子序列的长度；
	}
	return 0;
}
