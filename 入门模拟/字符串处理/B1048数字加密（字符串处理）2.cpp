#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b, c;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	if (lena > lenb)
		b.insert(b.begin(), lena - lenb, '0');
	else
		a.insert(a.begin(), lenb - lena, '0');
	char str[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
					'J', 'Q', 'K'};
	int flag = 1;
	for (int i = a.length()-1; i >= 0; i--) {
		if (flag == 1) {
			c += str[(a[i] - '0' + b[i] - '0') % 13];
			flag = 0;
		} else {
			int temp = b[i] - a[i];
			if (temp < 0) temp = temp + 10;
			c += str[temp];
			flag = 1;
		} 
	}
	for (int i = c.length()-1; i >= 0; i--) {
		cout << c[i];
	}
	return 0;
}

