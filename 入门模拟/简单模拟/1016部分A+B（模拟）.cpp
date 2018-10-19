#include <iostream> 
#include <string>
using namespace std;
int main()
{
	string A, B;  //用字符串存储数字 
	int Da, Db;
	cin >> A  >> Da >> B >> Db;
	int lenA = A.length(); //测出字符串长度 
	int lenB = B.length();
	int counta = 0, countb = 0;
	for (int i = 0; i < lenA; i++) {  //找处重复数字的个数 
		if (A[i] - '0' == Da)
			counta++;
	}
	for (int i = 0; i < lenB; i++) {
		if (B[i] - '0' == Db)
			countb++;
	}
	int ta = 0, tb = 0;   //在不等于0的时候，将ta，tb赋值为Da，Db 
	if (counta != 0) {
		ta = Da;
	}
	if (countb != 0) {
		tb = Db;
	}
	for (int i = 1; i < counta; i++) {  //相加 
		ta = 10 * ta + Da;
	}
	for (int i = 1; i < countb; i++) {
		tb = 10 * tb + Db;
	}
	cout << ta + tb;
	return 0;
}
