#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string a;
	getline(cin, a);
	int lena = a.length();
	int sum = 0;
	for (int i = 0; i < lena; i++) {
		if (isalpha(a[i])) {
			a[i] = tolower(a[i]);
			sum += (a[i] - 'a' + 1);
		} 
	}
	int count1 = 0, count2 = 0; 
	while (sum != 0) {
		if (sum % 2 == 0) {
			count1++;
		} else {
			count2++;
		}
		sum = sum / 2;
	}
	cout << count1 << " " << count2;
	return 0;
}

