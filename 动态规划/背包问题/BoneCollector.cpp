#include <iostream>
using namespace std;
int T, N, V;
int value[1001] = {0}, volume[1001] = {0};
int bag[1001][1001] = {0};
int main() {
	cin >> T >> N >> V;
	for (int j = 1; j <= T; j++) {
		for (int i = 1; i <= N; i++)
			cin >> value[i];
		for (int i = 1; i <= N; i++)
			cin >> volume[i];
		for (int i = 1; i <= N; i++) {
			for (int v = 1; v <= V; v++) {
				if (volume[i] > v)
					bag[i][v] = bag[i-1][v];
				else
					bag[i][v] = max(bag[i-1][v-volume[i]] + value[i], bag[i-1][v]);
			}
		}
		cout << bag[N][V];
	}
	return 0;
}

