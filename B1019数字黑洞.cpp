#include <iostream>
#include <algorithm>
#include <string> 
bool cmp(char a, char b) { return a > b; }
using namespace std;
int main()
{
	string s;
	cin >> s;
	s.insert(s.begin(), 4 - s.length(), '0');
	do {
			string a = s, b = s;
			sort(a.begin(), a.end(), cmp);
			sort(b.begin(), b.end());
			int result = stoi(a) - stoi(b);
			s = to_string(result);
			s.insert(s.begin(), 4 - s.length(), '0');
			cout << a << " - " << b << " = " << s << endl; 
	} while (s != "6174" && s!= "0000");
	return 0;
}

