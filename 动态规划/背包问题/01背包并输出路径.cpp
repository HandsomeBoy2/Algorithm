#include <iostream>
#include<algorithm>

using namespace std;
int main() {
	int total_weight = 10;
	int w[6] = { 0,5,4,3,2,1 };
	int v[6] = { 0,1,2,3,4,5 };
	int dp[11] = { 0 };
	int path[6][11] = { 0 };
	int i, j;
	for (i = 1; i <= 5; i++) {
		for (j = 10; j >= w[i]; j--) {
			if (dp[j] < dp[j - w[i]] + v[i]) {
				dp[j] = dp[j - w[i]] + v[i];
				path[i][j] = 1;

			}
			cout << dp[j] << "\t";
		}
		while (j > 0) {
			cout << 0 << "\t";
			j--;
		}
		cout << endl;
	}
	i = 5, j = 10;
	while (i > 0 && j > 0) {
		if (path[i][j] == 1) {
			cout << i << ' ';
			j -= w[i];
		}
		i--;
	}
	cout << endl;
	cout << "最大价值量为: " << dp[10] << endl;
	return 0;
}

