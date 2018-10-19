#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[100001], b[100001];
vector <int> v;
int main() {
	int i, N, lmax = 0;
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a+N);
	for(i = 0; i < N; i++){
		if (a[i] == b[i] && a[i] > lmax)
			v.push_back(a[i]);
		if (b[i] > lmax)
			lmax = b[i];
	}
	printf("%d\n", (int)v.size());
	for(i = 0; i < (int)v.size(); i++){
		if (i != 0) cout << " ";
		cout << v[i];
	}
	cout << "\n";
 	return 0;
}

