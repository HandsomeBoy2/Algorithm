#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0); //PI 
const double eps = 1e-5;   //精度 

double f(double R, double h){
	double alpha = 2 * acos((R-h)/R);  //弧度 
	double L = 2 * sqrt(R * R -(R-h)*(R-h)); //三角形底边长 
	double s1 = alpha * R * R / 2 - (R-h) * L / 2;  // 
	double s2 = PI * R * R / 2;
	return s1 / s2; 
}

double solve(double R, double r){
	double left = 0, right = R, mid;
	
	while(right - left > eps){
		mid = (left + right) / 2;
		if(f(R, mid) > r){
			right = mid;
		} else {
			left = mid;
		}
	}
	return mid;
}

int main(){
	double R, r;
	scanf("%lf %lf", &R, &r);
	printf("%lf", solve(R, r)); 
	return 0;
}
