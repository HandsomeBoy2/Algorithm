#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
	char c;
	int cnt = 1;
	string s;
	scanf("%c", &c);
	getchar();
	getline(cin, s);
	if (c == 'C') {
		for (int i = 0; i < s.length(); i++) {
			if (s[i+1] != s[i]) {
				if (cnt != 1) {
					cout << cnt;
				}
				cout << s[i];
				cnt = 1;
			} else
				cnt++;
		}
	} else {
		int cnt = 1;
		for (int i = 0; i < s.length(); i += cnt) {
			if (!isdigit(s[i])) {
				cnt = 1;
				cout << s[i];
			} else {
				cnt = 1;
				int k = 0;
				int num = s[i] - '0';
				while (isdigit(s[i+1+k])) {
					num = num * 10 + s[i+1] - '0';
					cnt++;
					k++;
				}
				for (int j = 0; j < num - 1; j++)
					cout << s[i+cnt];
			}
		}
	}
	return 0;
}

