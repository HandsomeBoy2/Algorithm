#include <iostream> 
using namespace std;
int main()
{
	int n, i = 0;
	int a[3] = {0};
	cin >> n;
	while (n != 0) 
	{
		a[i++] = n % 10;
		n = n / 10;
	}
	for (int k = 0; k < a[2]; k++)
		cout << "B";
	for (int k = 0; k < a[1]; k++)
		cout << "S";
	for (int k = 0; k < a[0]; k++)
		cout << k + 1;	
	return 0;
}

