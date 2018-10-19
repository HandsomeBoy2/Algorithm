#include <iostream>
#include <algorithm> 
#include <map>
using namespace std;
int main()
{
	char t;
	map<char, int> m;
	while(cin >> t) {
		if (t == 'P' || t == 'A' || t == 'T' || t == 'e' || t == 's' 
		|| t == 't')
		m[t]++;
	} 
	char c[7] = {"PATest"};
	int maxCnt = 0;
	for (auto it : m) {
		maxCnt = max(maxCnt, it.second);
	}
	for (int i = 0; i < maxCnt; i++) {
		for (int j = 0; j < 6; j++) {
			if (m[c[j]] != 0) {
				count << c[j];
				m[c[j]]--;
			}
		} 
	}
	return 0;
}

