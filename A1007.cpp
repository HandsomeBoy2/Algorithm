#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int i, n, sum = 0, maxSum = 0, cnt = 0, firstNum = 0, lastNum = 0;
	int flag = 1, sum1 = 0;
	cin >> n;
	vector <int> a(n+1);
	vector <int> b(n+1);
	a[0] = 0;
	b[0] = 0;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (i = 1; i <= n; i++) {
		if (b[i] >= 0)
			break;
	}
	if (i == n+1) {
		cout << 0 << " " << b[1] << " " << b[n];
		return 0; 
	}
	for (i = 1; i <= n; i++) {
		sum += a[i];
		if (sum <= 0)
			sum = 0;
		a[i] = max(sum, a[i-1]);
		if (sum == a[i]) {
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (maxSum == a[i] && a[i] != 0 && flag == 1) {
			lastNum = b[i];
			cnt = i;
			flag = 0;
		}
	}
	for (i = cnt; i > 0; i--) {
		sum1 += b[i];
		if (sum1 == maxSum) {
			firstNum = b[i];
		}
	}	
	cout << maxSum << " " << firstNum << " " << lastNum;
	return 0;
}
