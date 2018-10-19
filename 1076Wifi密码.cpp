#include <iostream>
#include <string>
#include <vector> 
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector <int> b(n);
	for (int i = 0; i <= n; i++) {
		 	string a;
		 	getline(cin, a);
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == 'T') {
				b[i] = a[j-2] - 'A' + 1;
				continue;
			}	
		}
	}
	for (int i = 1; i <= n; i++)
		cout << b[i];
 	return 0;
}

