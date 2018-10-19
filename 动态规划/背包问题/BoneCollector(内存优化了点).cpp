#include <iostream>
using namespace std;
int T, N, V;
int value[1001] = {0}, volume[1001] = {0};
int bag[1001] = {0};
int main() {
	cin >> T >> N >> V;
	for (int j = 1; j <= T; j++) {
		for (int i = 1; i <= N; i++)
			cin >> value[i];
		for (int i = 1; i <= N; i++)
			cin >> volume[i];
		for (int i = 1; i <= N; i++) {
			for (int v = V; v >= 1; v--) {
				if (volume[i] <= v)
					bag[v] = max(bag[v-volume[i]] + value[i], bag[v]);
			}
		}
		cout << bag[V];
	}
	return 0;
}

