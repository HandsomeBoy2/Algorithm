#include <iostream>
#include <math.h>
using namespace std;
bool isprime(int n)
{
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) 
			return false;
	}
	return true;
}
int main()
{
	int n, count = 0;
	cin >> n;
	for (int i = 3; i <= n; i += 2) {
		if(isprime(i) && isprime(i-2)) {
			count++;
			i += 2;
		}	 
	}
	cout << count;
	return 0;
}

