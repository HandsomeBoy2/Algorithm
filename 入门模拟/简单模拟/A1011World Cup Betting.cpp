#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	double first, second, third;
	double sum = 1.0f;
	char s[3];
	for (int i = 0; i < 3; i++) {
		cin >> first >> second >> third;
		if (first > second && first > third) {
			sum *= first;
			s[i] = 'W';
		} else if (second > first && second > third) {
			sum *= second;
			s[i] = 'T';
		} else if (third > first && third > second) {
			sum *= third;
			s[i] = 'L';
		}
	}
	printf("%c %c %c %.2lf", s[0], s[1], s[2], (sum * 0.65 - 1 ) * 2);
	return 0;
}

