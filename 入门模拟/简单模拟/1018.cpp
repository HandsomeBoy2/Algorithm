#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char jia, yi;
	int jiayin = 0, yiyin = 0;
	int jia1 = 0, jia2 = 0, jia3 = 0;
	int yi1 = 0, yi2 = 0, yi3 = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%c %c", &jia, &yi);
		getchar();
		if (jia == 'C' && yi == 'J') {
			jiayin++;
			jia1++;
		} else if (jia == 'C' && yi == 'B') {
			yiyin++;
			yi1++;
		} else if (jia == 'J' && yi == 'B') {
			jiayin++;
			jia2++;
		} else if (jia == 'J' && yi == 'C') {
			yiyin++;
			yi2++;
		} else if (jia == 'B' && yi == 'C') {
			jiayin++;
			jia3++;
		} else if (jia == 'B' && yi == 'J') {
			yiyin++;
			yi3++;
		} 
	}
	char c = (jia3 > jia1) ? 'B' : ((jia1 > jia2) ? 'C' : 'J');  
	char c1 = (yi1 > yi2 ) ? 'B' : ((yi2 > yi3) ? 'C' : 'J'); 
	printf("%d %d %d\n", jiayin, n - yiyin - jiayin, yiyin);
	printf("%d %d %d\n", yiyin, n - yiyin - jiayin, jiayin);
	printf("%c %c", c, c1);
	return 0;
}

