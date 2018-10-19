#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int i, n;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	if (a[n-1] <= 0) {
		printf("1");
		return 0;
	}		
	for (i = 0; i < n-1; i++) {
		if (a[i] >= 0 && a[i+1]-a[i] >= 2){
			printf("%d", a[i]+1);
			return 0;
		}
	}
	printf("%d", a[n-1]+1);
 	return 0;
}

