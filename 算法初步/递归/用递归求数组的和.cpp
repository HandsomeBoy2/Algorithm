#include <iostream>
using namespace std;
int f(int a[], int begin) {
	if (begin == 10) return 0;
	int x = f(a, begin+1);
	return a[begin] + x; 
}
int f1(int a[], int end) {
	if (end < 0) return 0;
	int x = f(a, end-1);
	return a[end] + x;
}
int f2(int a[], int begin, int end) {
	int middle = (begin + end) / 2;
	if(begin < end){  
        return f2(a, begin, middle) + f2(a, middle+1, end);     
    } 
	if(begin == end){  
        return a[end];  
    }  
} 
int main() {
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	int sum = f(a, 0);
	int sum1 = f1(a, 10);
	int sum2 = f2(a, 0, 5) + f2(a, 6, 10); 
	cout << sum << endl;
	cout << sum << endl;
	cout << sum << endl;
 	return 0;
}

