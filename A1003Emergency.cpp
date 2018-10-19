#include <iostream>
using namespace std;
int N, M, b, e, C1, C2, length, min1 = 999999;
int res[501] = {0}, nres = 0, num = 0;
void dfs(int b, int dis, int n) {
	if (dis > min1) return; 
	if (b == e) {
		if (dis == min1) {
			num++;
			if (n > nres)
				nres = n; 
		}
		if (dis < min1) {
			num = 1;
			min1 = dis;
			nres = n;
		}
		return;
	}
	for (int i = 0; i <= N; i++) {
		if (a[b][i] != 0 && book[i] == 0) {
			book[i] = 1;
			dfs(i, dis + a[b][i], n + res[i]);
			book[i] = 0;
		}
	}
}
int main() {
	int i;
	cin >> N >> M >> b >> e;
	for (i = 0; i < N; i++)
		cin >> res[i];
	for (i = 0; i < M; i++) {
		cin >> C1 >> C2 >> length;
		a[C1][C2] = length;
		a[C2][C1] = length;
	}
	book[b] = 1;
	dfs(b, 0, res[b]);
	book[b] = 0;
	
	printf("%d %d", num, nres);
	return 0;
}
