#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b, c;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	for (int i = 0; i <= lena / 2 - 1; i++) {
		swap(a[i], a[lena-i-1]);
	}
	for (int i = 0; i <= lenb / 2 - 1; i++) {
		swap(b[i], b[lenb-i-1]);
	}
	if (lena > lenb)
		b.append(lena - lenb, '0');
	else
		a.append(lenb - lena, '0');
	char str[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
					'J', 'Q', 'K'};
	for (int i = 0; i < a.length(); i++) {
		if (i % 2 == 0) {
			c += str[(a[i] - '0' + b[i] - '0') % 13];
		} else {
			int temp = b[i] - a[i];
			if (temp < 0) temp = temp + 10;
			c += str[temp];
		} 
	}
	for (int i = c.length() - 1; i >= 0; i--) {
		cout << c[i];
	}
	return 0;
}

