#include <iostream>
struct student
{
	char name[100];
	char num[100];
	int grade;
};
using namespace std;
int main()
{
	int n;
	cin >> n;
	struct student stu[n];
	int t = 0, t1 = 0, max = 0, min = 101;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].num >> stu[i].grade;
		if (max <= stu[i].grade) {
			max = stu[i].grade;
			t = i;
		}
		if (min >= stu[i].grade) {
			min = stu[i].grade;
			t1 = i;
		}
	} 
	cout << stu[t].name << " " << stu[t].num << endl;
	cout << stu[t1].name << " " << stu[t1].num << endl;	
	return 0;
}

