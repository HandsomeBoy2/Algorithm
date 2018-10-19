#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long change(string a, long long radix) {
	long long sum = 0;
	long long temp = 0;
	for (long long i = a.length()-1; i >= 0; i--) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			sum += (a[i] - 'a' + 10) * pow(radix, temp++);
		} else if (a[i] >= '0' && a[i] <= '9') {
			sum += (a[i] - '0') * pow(radix, temp++);
		}
	}
	return sum;
}
long long getLowRadix(string a) {
	long long least = 0;
	long long num = 0;
	for (long long i = 0; i < a.length(); i++) {
		if (a[i] >= 'a' && a[i] <= 'z') 
			num = a[i] - 'a' + 10;
		else if (a[i] >= '0' && a[i] <= '9') 
			num = a[i] - '0';
		if (num+1 > least) 
			least = num + 1;
	}
	return least;
}
long long compare(string a, long long radix, long long target) {
	long long temp = 0, sum = 0;
	for (long long  i = a.length() - 1; i >= 0; i--) {
		if (a[i] >= 'a' && a[i] <= 'z')
			sum += (a[i] - 'a' + 10) * pow(radix, temp++);
		else if (a[i] >= '0' && a[i] <= '9')
			sum += (a[i] - '0') * pow(radix, temp++);
		if (sum > target)
			return 1;
	}
	if (sum > target)
		return 1;
	else if (sum < target)
		return -1;
	else 
		return 0;
}
long long binarySearch(string a, long long low, long long high, long long target) {
	long long mid = low;
	long long temp;
	while (low <= high) {
		temp = compare(a, mid, target);
		if (temp > 0) {
			high = mid - 1;
		} else if (temp < 0) {
			low = mid + 1;
		} else {
			return mid;
		}
		mid = (low + high) / 2;
	}
	return -1;
}
int main() {
	string A, B;
	long long tag, radix, least = 0, most = 0;
	long long target = 0, result = 0;
	cin >> A >> B >> tag >> radix;
	if (tag == 1) {
		target = change(A, radix);
		least = getLowRadix(B);
		most = (target + 1 > least + 1) ? target + 1 : least + 1;
		result = binarySearch(B, least, most, target);
		if (result == -1) {
			cout << "Impossible";
		} else {
			cout << result;
		}
	} else if (tag == 2) {
		target = change(B, radix);
		least = getLowRadix(A);
		most = (target + 1 > least + 1) ? target + 1 : least + 1;
		result = binarySearch(A, least, most, target);
		if (result == -1) {
			cout << "Impossible";
		} else {
			cout << result;
		}
	}
	return 0;
}

