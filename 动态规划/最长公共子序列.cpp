#include <iostream>
#include <string.h>
#include <algorithm>
#define Max 100
using namespace std;
char strA[Max], strB[Max], mark[Max][Max];
//打印输出最长公共子序列
void print(int i, int j) {
	if(i==0 || j==0) return;
	if(mark[i][j] == 0) {
		print(i-1, j-1);
		cout  << strA[i-1];
	} else if(mark[i][j] == 1)
		print(i-1, j);
	else print(i, j-1);
}

int main() {
	cin >> strA;
	cin >> strB;
	int lenA = strlen(strA), lenB = strlen(strB);
	int maxn[Max][Max] = {0};
	int i, j;
	for(i = 1; i <= lenA; i++) {
		for(j = 1; j <= lenB; j++) {
			if(strA[i-1] == strB[j-1]) {
				maxn[i][j] = maxn[i-1][j-1] + 1;
				mark[i][j] = 0;
			} else {
				if(maxn[i-1][j] > maxn[i][j-1]) {
					maxn[i][j] = maxn[i-1][j];
					mark[i][j] = 1;
				} else {
					maxn[i][j] = maxn[i][j-1];
					mark[i][j] = -1;
				}
			}
		}
	}
	print(lenA, lenB);
	cout << endl;
	cout << maxn[lenA][lenB] << endl;
	return 0;
}
