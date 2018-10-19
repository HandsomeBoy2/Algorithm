#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, max = 0, cnt = 0;
	cin >> n;
	vector <int> a(n); 
	vector <int> b(n);
	vector <int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	} 
	sort(a.begin(), a.begin() + n);
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] > max) {
			c[cnt++] = a[i];
		}
		if (b[i] > max) {
			max = b[i];
		}	
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		if (i != 0) cout << " ";
		cout << c[i];
	}
	cout << endl;
	return 0;
}

