#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	char A, B;
	cin >> a >> A >> b >> B;
	int cntA = 0, cntB = 0;
	int numa = A - '0', numb = B - '0';
	int sumA = 0, sumB = 0; 
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == A)
			cntA++;
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == B)
			cntB++;
	}
	for (int i = 0; i < cntA; i++) {
		sumA += numa;
		numa = numa * 10;
	}
	for (int i = 0; i < cntB; i++) {
		sumB += numb;
		numb = numb * 10;
	}
	int sum = sumA + sumB;
	cout << sum;
	
	return 0;
}

