#include <iostream>
using namespace std;
int main() {
	int bag[6][11] = {0};
	int weight[6] = {0, 2, 2, 6, 5, 4};
	int value[6] = {0, 6, 3, 5, 4, 6};
	for (int i = 1; i <= 5; i++) {
		for (int v = 1; v <= 10; v++) {
			if (weight[i] > v)
				bag[i][v] = bag[i-1][v];
			else 
				bag[i][v] = max(bag[i-1][v-weight[i]] + value[i], bag[i-1][v]);
		}
	}
	cout << bag[5][10];
 	return 0;
}

