#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	bool flag = true;
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	char cnt1, cnt2;
	int cnt3, num1, num2;
	int min1 = a.length() > b.length()? b.length() : a.length();
	int min2 = c.length() > d.length()? d.length() : c.length();
	for (int i = 0; i < min1; i++) {
		if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G' && flag) {
			cnt1 = a[i];
			flag = false;
			continue;
		}
		if (a[i] == b[i] && (!flag) && ((a[i] >= '0' && a[i] <= '9' )
								 || (a[i] >= 'A' && a[i] <= 'N'))) {
			cnt2 = a[i];
			break;
		}
	}
	for (int i = 0; i < min2; i++) {
		if (c[i] == d[i] && ((c[i] >= 'a' && c[i] <= 'z') || c[i] >= 'A' && c[i] <= 'Z')) {
			cnt3 = i;
			break;
		}	 
	}
	if (cnt1 >= 'A' && cnt1 <= 'G')
		num1 = cnt1 - 'A'; 
	if (cnt2 >= 'A' && cnt2 <= 'N') 
		num2 = cnt2 - 'A' + 10;
	else
		num2 = cnt2 - '0';
	cout << day[num1] << " ";
	printf("%02d:%02d",  num2, cnt3);
	return 0;
}

