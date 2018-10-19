#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int max = 0, min = 500;
	char str[500];
	char strmax[500];
	char strmin[500];
	while (scanf("%s", str) != EOF) {
		if (strlen(str) > max) {
			max = strlen(str);
			strcpy(strmax, str);
		}
		if (strlen(str) < min) {
			min = strlen(str);
			strcpy(strmin, str);
		}			
		char c = getchar();
		if (c == '\n') {
			puts(strmax);
			puts(strmin);
		}	 
	}
	return 0;
}

