#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
#ifdef LOCAL
	freopen("testin.txt", "r", stdin);
	freopen("testout.txt","w", stdout);
#endif
	int n, cnt = 0;
	cin >> n;
	vector <int> a(n);
	vector <int> b(n);
	vector <int> c(n); 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int sum = 0;
		while (a[i] != 0) {
			sum += a[i] % 10;
			a[i] /= 10;
		}
		b[i] = sum;
	}
	sort(b.begin(), b.end());
	int j = 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i+1] != b[i]) {
			c[j++] = b[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < j; i++) {
		cout << c[i];
		if (i != j - 1) {
			cout << " ";
		}
	}
 	return 0;
}

