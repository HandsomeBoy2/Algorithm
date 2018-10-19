#include <stdio.h>
#include <limits.h>
int a[INT_MAX] = {0};
int main() {
	int i, n, num = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num >= 0) {
			a[num] = 1;
		}
	}		
	if (a[0] == 0 && a[1] == 0){
		printf("1");	
		return 0;
	}
	for (i = 1; i < INT_MAX; i++) {
		if (a[i] == 0){
			printf("%d", i);
			break;
		}
	}
 	return 0;
}

