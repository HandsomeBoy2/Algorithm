#include <iostream>
#include <vector>
using namespace std;
int N;
struct Node {
	int num;
	bool flag = false;
};
int main() {
	int i, upTime = 0, downTime = 0, waitTime = 0;
	cin >> N;
	struct Node node[N+2];
	vector <int> a;
	node[0].num = 0;
	node[0].flag = true;
	node[N+1].num = 0;
	node[N+1].flag = true;
	for (i = 1; i <= N; i++) {
		cin >> node[i].num;
		if (i == 1 || i == N) {
			node[i].flag = true;
		}
		if (node[i].num > node[i-1].num && node[i].num > node[i+1].num) {
			node[i].flag = true;
		}
		if (node[i].num < node[i-1].num && node[i].num < node[i+1].num) {
			node[i].flag = true;
		}
	}
	for (i = 0; i <= N+1; i++) {
		if (node[i].flag == true) {
			a.push_back(node[i].num);
		}
	}
	waitTime = N * 5;
	for (i = 1; i < a.size() - 1; i++) {
		if (a[i] > a[i-1]) {
			upTime += (a[i] - a[i-1]) * 6;
		}
		if (a[i] < a[i-1]) {
			downTime += (a[i-1] - a[i]) * 4;
		}
	}
	cout << upTime+downTime+waitTime;
	return 0;
}
