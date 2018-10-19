#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	string id, signin, signout;
	string ed, ld;
	int maxtime = -1, mintime = 99999999;
	int time = 0, time1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> signin >> signout;
		time = ((signin[0] - '0') * 10 + signin[1] - '0') * 3600 +
		       ((signin[3] - '0')* 10 + (signin[4] - '0')) * 60 +
		       (signin[6] - '0') * 10 + signin[7] - '0';
		time1 = ((signout[0] - '0') * 10 + signout[1] - '0') * 3600 +
		       ((signout[3] - '0')* 10 + (signout[4] - '0')) * 60 +
		       (signout[6] - '0') * 10 + signout[7] - '0';            
		if (time1 > maxtime) {
			maxtime = time1;
			ld = id;
		}
		if (time < mintime) {
			mintime = time;
			ed = id;
		}
	}
	cout << ed << " " << ld;
	return 0;
}

