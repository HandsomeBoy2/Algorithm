#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	int sum[N] = {0};
	vector <int> a(M);
	vector <int> b(M);
	vector <int> c(M);
	for (int i = 0; i < M; i++) 
		cin >> a[i];
	for (int j = 0; j < M; j++) 
		cin >> b[j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c[j];
			if (c[j] != b[j])
				continue;
			else 
				sum[i] += a[j];
		} 
	}	
	for (int j = 0; j < N; j++) 
		cout << sum[j] << endl;
	return 0;
}

