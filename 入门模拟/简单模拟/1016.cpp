#include <iostream>
#include <string> 
using namespace std;
int main()
{
	string a, b;
	int A, B;
	int cnt1 = 0, cnt2 = 0;
	cin >> a >> A >> b >> B;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' == A)
			cnt1++;
	} 
	for (int i = 0; i < b.length(); i++) {
		if (b[i] - '0' == B)
			cnt2++;
	} 
	if (cnt1 != 0) {
		t1 = A;
	}
	if (cnt2 != 0) {
		t2 = B;
	}
	for (int i = 1; i < cnt1; i++)
		t1 = t1 * 10 + A;
	for (int i = 1; i < cnt2; i++) 
		t2 = t2 * 10 + B;
	cout << t1 + t2;
	return 0;
}

