#include <stdio.h>
int main()
{
	int a, b;
	bool flag = true;
	while (scanf("%d %d", &a, &b) != EOF) {
		if (b == 0)	continue;
		if (!flag) 
			printf(" ");
		else 
			flag = false;
		printf("%d %d", a * b, b - 1);
	}		
	if (flag)
		printf("0 0");
	return 0;
}

