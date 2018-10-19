#include <stdio.h>
int i, j, k, k1, index, index1, cnt = 0;
float num = 0, num1 = 0;
float a[3000] = {0}, a1[3000] = {0}, a3[3000] = {0};
int main() {
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d%f", &index, &num);
		a[index] = num;
	}
	scanf("%d", &k1);
	for (i = 0; i < k1; i++) {
		scanf("%d%f", &index1, &num1);
		a1[index1] = num1;
	}
	for (i = 0; i < 3000; i++) {
		for (j = 0; j < 3000; j++) {
			if (a[i] != 0 && a1[j] != 0)
				a3[i+j] += a[i] * a1[j];
		}
	}
	for (i = 0; i < 3000; i++) {
		if (a3[i] != 0)
			cnt++;
	}
	printf("%d", cnt);
	for (i = 3000; i >= 0; i--) {
		if (a3[i] != 0) {
			printf(" %d %.1f", i, a3[i]);
		}
	}
	return 0;
}

