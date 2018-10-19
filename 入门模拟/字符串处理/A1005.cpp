#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s;
	vector <int> v;
	string english_num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}
	if (sum == 0)
		v.push_back(0);
	while (sum != 0) {
		v.push_back(sum%10);
		sum /= 10;
	}
	for (int i = v.size() - 1; i > 0; i--) {
		cout << english_num[v[i]] << " ";
	}
	cout << english_num[v[0]];
 	return 0;
}

