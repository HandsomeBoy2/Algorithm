#include <iostream>
using namespace std;
int main() {
	int n, w;
	cin >> n >> w;
	int temp = 0;
	int w1[n+1] = {0}, v[n+1] = {0};
	int dp[w+1] = {0}, path[n+1][w+1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> w1[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for(int j = w; j >= w1[i]; j--) {
			if (dp[j] < dp[j-w1[i]]+v[i]) {
				dp[j] = dp[j-w1[i]]+v[i];
				path[i][j] = 1; 
			} 
		}
	}
	cout << endl;
	int i = 5, j = 10;
	while (i > 0 && j > 0) {
		if (path[i][j] == 1) {
			cout << i << " ";
			j -= w1[i];
		}
		i--;
	} 
	cout << endl;
	cout << dp[w] << endl;
 	return 0;
}

