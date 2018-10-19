/*其状态转移方程为：
F[i]=MAX(F[1],…F[j]…,F[i-1]，其中所选的一项必须能与F[i]相连接)+1
下标为j所在的数必须小于等于i所在的数 */ 
#include <iostream>
#include <algorithm>
#define Max 100 
using namespace std;
int main(){
	int n, a[Max], maxn, mark[Max] = {0};
	cin >> n;//要输入数字的个数
	int num[n];//前i项中的最长不下降子序列的长度存放在num[i]中.
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		num[i] = 1;
		for(int j = 1; j <= i; j++){ //j表示i之前的所有的数 
			if(a[j]< a[i])//状态方程
			num[i] = max(num[j]+1, num[i]);
		}
		maxn = max(maxn, num[i]);
	}
//	 for(int i = 1; i <= n; i++){ 求出最长不下子序列长度 
//	 	if(max < num[i])
//	 		max = num[i];
//	 }
	 cout << maxn << endl;
	 return 0;
} 
