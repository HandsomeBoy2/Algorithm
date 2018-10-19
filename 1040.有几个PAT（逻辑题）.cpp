#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int lena = a.length(), countP = 0, countA = 0, countT = 0;
	int result = 0;
	for (int i = 0; i < lena; i++) {
		if (a[i] == 'T') {
			countT++;
		}
	}
	for (int i = 0; i < lena; i++) {
		if (a[i] == 'P') countP++;
		if (a[i] == 'T') countT--;
		if (a[i] == 'A') {
			result = (result + (countP * countT) % 1000000007) % 1000000007;
		}	
	}
	cout << result;
	return 0;
}

