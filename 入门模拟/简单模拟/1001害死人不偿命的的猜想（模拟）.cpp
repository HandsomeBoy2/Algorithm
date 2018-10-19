#include <iostream> 
using namespace std;
int main()
{
	int n;
	cin >> n;
	int count = 0;
	while (n != 1) {
		while (n % 2 != 0) {
			n = 3 * n +1;
		}
		n = n / 2;
		count++;
	}
	cout << count;
	return 0;
}
 
