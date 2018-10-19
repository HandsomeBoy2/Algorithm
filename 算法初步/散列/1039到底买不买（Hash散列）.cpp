#include <iostream>
#include <string> 
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < b.length(); i++) { //查找并标记 
		for (int j = 0; j < a.length(); j++) {
			if (b[i] == a[j]) {
				a[j] = '#';
				b[i] = '#';
			}
		}
	}
	int count1 = 0, count2 = 0;
	for (int i = 0; i < a.length(); i++) { //统计 
		if (a[i] != '#') {
			count1++;
		}
	}
	for (int i = 0; i < b.length(); i++) { //统计 
		if (b[i] != '#') {
			count2++;
		}
	}
	if (count2 != 0) 
		cout << "No " << count2;
	else
		cout << "Yes " << count1;
	
	return 0;
}

