#include <iostream>
#include <cstdio> 
using namespace std;
int main()
{
	int n;
	cin >> n;
	int team, number, grade;
	int a[1001] = {0};  //存储每个队伍总分 
	for (int i =0; i < n; i++) {
		scanf("%d-%d %d", &team, &number, &grade);
		a[team] = a[team] + grade;
	}
	int t = 0, max = a[0];
	for (int i = 0; i < 1001; i++) {
		if (max < a[i]) {
			max = a[i];
			t = i;
		}
	}
	cout << t << " " << max;
	return 0;
}

