#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int n, i, j;
	long long result;
	while (scanf("%d", &n) != EOF) {
		result = 1;
		j = 0;
		for (i = 1; i <= n; i++) {
			result *= i;
		}
		printf("result=%lld\n", result);
		while(result) {
			if ((result % 10) == 0)
				j++;
			else
				break;
			result /= 10;
		}
		printf("%d\n", j);
	}
	return 0;
}
