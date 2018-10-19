#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, sum1 = 0, sum2 = 0, count3 = 0, count4 = 0, max5 = 0;
	bool flag = true, flag5 = false;
	float sum4 = 0.0f;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 5 == 0 && a[i] % 2 == 0) {
			sum1 += a[i];
			continue;
		} else if (a[i] % 5 == 1) {
			if (flag) {
				sum2 += a[i];
				flag = false;
			} else {
				sum2 -= a[i];
				flag = true;
			}
			continue;
		} else if (a[i] % 5 == 2) {
			count3++;
			continue;
		} else if (a[i] % 5 == 3) {
			sum4 += a[i];
			count4++;
			continue;
		} else if (a[i] % 5 == 4) {
			if (a[i] > max5) {
				max5 = a[i];
				flag5 = true;
			}
				
		}
	}
	if (sum1 == 0) {
		cout << 'N' << " "; 
	} else {
		cout << sum1 << " ";
	}
	if (sum2 == 0) {
		cout << 'N' << " "; 
	} else {
		cout << sum2 << " ";
	}
	if (count3 == 0) {
		cout << 'N' << " "; 
	} else {
		cout << count3 << " ";
	}
	if (count4 == 0) {
		cout << 'N' << " ";     
	} else {
		printf("%.1f ", sum4 / count4);
	}
	if (flag5) {
		cout << max5;
	} else {
		cout << 'N';
	}
	
	return 0;
}

