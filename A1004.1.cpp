#include <iostream>
#include <vector>
using namespace std;
vector <int> node[205];
int book[205], maxdepth = -1;
int N, M, father, num, child;
void dfs(int index, int depth) {
	if (node[index].size() == 0) {
		book[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < node[index].size(); i++) 
		dfs(node[index][i], depth+1);
}
int main() { 
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> father >> num;
		for (int j = 1; j <= num; j++) {
			cin >> child;
			node[father].push_back(child);
		}
	}
	dfs(1, 0);
	cout << book[0];
	for (int i = 1; i <= maxdepth; i++)
		cout << " " << book[i];
	return 0;
}

