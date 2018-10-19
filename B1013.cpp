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
	int M, N, cnt = 0;
	int i = 2, j = 0, a[10000];
	cin >> M >> N;
	while (cnt < N) {
		if (isprime(i)) {
			cnt++;
			if (cnt >= M) {
				a[j++] = i;
			}	
		}
		i++;
	}
	for (int i = 0; i < j; i++) {
		cout << a[i];
		if ((i + 1) % 10 == 0) 
			cout << endl;
		else if (i != j - 1)
			cout << " ";
			
	}
	return 0;
}

