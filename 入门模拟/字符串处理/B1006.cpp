#include <iostream>
using namespace std;
int main()
{
	int n, i = 1, j, t = 1;
	cin >> n;
	int a[5];
	while (n != 0) {
		a[i++] = n % 10;
		n = n / 10;
	}
	while (a[3] != 0) {
		cout << 'B';
		a[3]--;
	}	
	while (a[2] != 0) {
		cout << 'S';
		a[2]--;
	}
	while (a[1] != 0) {
		cout << t;
		t++;
		a[1]--;
	}
	return 0;
}

