#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N, M;  //N位 移动M位 
	cin >> N >> M;   //M小于N  或  M大于N 
	int a[N] = {0};
	for (int i = 0; i < N; i++) 
		cin >> a[i];   		// 1 2 3 4 5 6
	if (M != N) {
		while (M > N) M = M - N;
		reverse(a, a + N);		// 6 5 4 3 2 1
		reverse(a, a + M);		// 5 6 4 3 2 1
		reverse(a + M, a + N);	// 5 6 1 2 3 4
	}  
	for (int i = 0; i <= N - 2; i++) 
		cout << a[i] << " ";
	cout << a[N-1];
	return 0;
}

