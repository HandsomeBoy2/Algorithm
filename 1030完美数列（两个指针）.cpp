#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
int main()
{
	int n;
	long long int p;
	cin >> n >> p;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int result = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + result; j < n; j++) {
			if (a[j] <= a[i]*p) {
				temp = j-i+1;
				if (temp > result) {
					result = temp;
				}
			} else {
				break;
			}
		}
	}
	cout << result;
	return 0;
}

