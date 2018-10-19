#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int lena = a.length();
	int sum = 0, n = 0, i = 0, j = 0;
	int b[100];
	string str[10]= {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}; 
	for (i = 0; i < lena; i++) {
		sum += a[i] - '0';
	}
	i = 0;
	while (sum != 0) {
		b[i++] = sum % 10;   
		sum = sum / 10;
	}
	for (j = i - 1; j > 0; j--) 
		cout << str[b[j]] << " "; 
	cout << str[b[0]];
	return 0;
}

