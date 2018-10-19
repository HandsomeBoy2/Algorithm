#include <cstdio>
#include <iostream>

using namespace std;
double x1, x2;
double f(double x){
	return x*x + 3*x - 4;
}
double eps = 1e-5;
double solve(double left, double right){
	double mid;
	while(right - left > eps){
		mid = left + (right - left) / 2;
		if(f(mid) < 0){
			right = mid;
		} else {
			left = mid;
		} 
	}
	return mid;
}

int main(){
	x1 = -5, x2 = 0;
	
	cout << solve(x1, x2);
	return 0;
} 
