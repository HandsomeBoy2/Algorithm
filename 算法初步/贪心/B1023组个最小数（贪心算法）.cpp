#include <iostream>
using namespace std;
int main()
{
	int a[10], temp;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < 10; i++) {
		if (a[i] != 0) {
			cout << i;
			temp = i;
			break;
		}
	} 
	for (int i = 0; i < a[0]; i++) {
		cout << 0;
	}
	for (int i = 0; i < a[temp]-1; i++) {
		cout << temp;
	}
	for (int i = temp+1; i < 10; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
