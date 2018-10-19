#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int jia, jiahua, yi, yihua;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> jia >> jiahua >> yi >> yihua;
		if ((jia + yi == jiahua) && (jia + yi != yihua)) {
			count2++;
		} else if ((jia + yi == yihua) && (jia + yi != jiahua)) {
			count1++;
		} else continue;	
	}
	cout << count1 << " "<< count2;
	return 0;
}
