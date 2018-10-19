#include <iostream>
#include <string> 
using namespace std;
int main()
{
	int n, grade;
	int max = 0, min = 101; 
	cin >> n;
	string name, num, maxname, maxnum, minname, minnum;
	for (int i = 0; i < n; i++) {
		cin >> name >> num >> grade;
		if (grade >= max) {
			max = grade;
			maxname = name;
			maxnum = num;
		}
		if (grade <= min) {
			min = grade;
			minname = name;
			minnum = num;
		}		
	}
	cout << maxname << " " << maxnum << endl;
	cout << minname << " " << minnum;
	return 0;
}

