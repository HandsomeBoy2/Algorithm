#include <iostream>
#include <algorithm>
using namespace std;
bool cmp (int a, int b) 
{
	return a > b;
}
int main()
{
	int i, j, k;
	cin >> k;
	int a[k];
	for (i = 0; i < k; i++) {
		cin >> a[i];	
	}
	sort(a, a+k, cmp);
	for (i = 0; i < k; i++) {
		int t = a[i];
		while (t != 1 && t != 999) {
			if (t % 2 == 0) {
		 		t = t / 2; 
			} else {
		 		t = (t * 3 + 1) / 2;
			} 
			for (j = k - 1; j >= 0; j--) {
				if (t == a[j] && i != j) {
					a[j] = 999;
				}
			}
		}
	} 
	sort(a, a+k);
	int temp;
	for (i = 0; i < k; i++) {
		if (a[i] != 999) 
			temp = i;
	} 
	for (j = temp; j > 0; j--) {
		cout << a[j] << " ";
	}
	cout << a[0];
	return 0;
}

