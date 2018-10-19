/**
快速幂的递归写法 
**/
#include <cstdio>
#include <iostream>
using namespace std;
int binaryPow(long long int a, long long b, long long m){
	if(b == 0) return 1;
	if(b % 2 == 1) {
		return a*binaryPow(a, b-1, m); 
	} else {
		long long int mul = binaryPow(a, b/2, m);
		return mul*mul%m;	
	}		
}
int main(){
	long long int a, b, m;
	cin >> a >> b >> m;
	
	int result = binaryPow(a, b, m);
	printf("%d", result);
	return 0;
}
