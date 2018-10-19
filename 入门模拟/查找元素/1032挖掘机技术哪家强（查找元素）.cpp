#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, num, score;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> num >> score;
		a[num] += score;
	}
	int j = 1, max = a[1];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			j = i;
		}
	}
	cout << j << " " << max; 
	return 0;
}

