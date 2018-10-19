#include <iostream>
using namespace std;
int N, M;
int value[1001] = {0}, volume[1001] = {0};
int bag[1001] = {0};
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> volume[i] >> value[i];
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= 1; j--) {
			if (volume[i] <= j)
				bag[j] = max(bag[j-volume[i]] + value[i], bag[j]);
		}
	}
	cout << bag[M];
	return 0;
}

