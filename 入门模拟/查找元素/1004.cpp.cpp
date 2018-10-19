#include <iostream>
using namespace std;
struct stu
{
	char name[11];
	char num[11];
	int grade;
};
int main()
{
	int n, t, t1, max = 0, min = 101;
	cin >> n;
	struct stu person[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> person[i].name >> person[i].num >> person[i].grade;
		if (person[i].grade >= max) {
			max = person[i].grade;
			t = i;
		}
		if (person[i].grade <= min) {
			min = person[i].grade;
			t1 = i;
		}
	}
	cout << person[t].name <<  " " << person[t].num << endl;
	cout << person[t1].name <<  " " << person[t1].num << endl;
	return 0;
}

