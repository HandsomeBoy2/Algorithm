#include <iostream>
#include <vector>
#include <algorithm> 
#include <memory.h>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int func(int N) 
{
	int i = sqrt((double)N);
	while(i >= 1) {
		if (N % i == 0) 
			return i;
		i--;
	}
	return 1;
}

int main()
{
	int N, m, n;
	cin >> N;
	n = func(N);
	m = N / n;
	vector <int> a(N);
	int b[m][n];
	memset(b, -1, sizeof(b));
	for (int k = 0; k < N; k++) {
		cin >> a[k];
	}
	sort(a.begin(), a.begin() + N, cmp); 
	int total = 0;
	int i = 0, j = 0;
	while (total < N) {
			while (j <= n-1 && b[i][j] == -1) { //right
				b[i][j] = a[total++];
				j++;
			}
			i++;
			j--;
			while (i <= m-1 && b[i][j] == -1) { //down
				b[i][j] = a[total++];
				i++;
			}
			i--;
			j--;
			while (j >= 0 && b[i][j] == -1) { //left
				b[i][j] = a[total++];
				j--;
			}
			j++;
			i--;
			while (i >= 0 && b[i][j] == -1) { //up
				b[i][j] = a[total++];
				i--;
			}
			i++;
			j++;		
	}
	for (int k = 0; k < m; k++) {
		for (int l = 0; l < n; l++) {
			cout << b[k][l];
			if (l != n - 1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}

