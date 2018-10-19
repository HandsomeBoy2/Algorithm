#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, sum = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum = sum + a[i] * (n - 1) + a[i] * 10 * (n - 1);
	}
	cout << sum;
	return 0;
}

