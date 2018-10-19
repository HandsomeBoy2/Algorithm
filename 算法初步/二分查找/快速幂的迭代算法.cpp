/**
快速幂的迭代算法 
**/ 
#include <cstdio>
#include <iostream>
using namespace std;

long long int binaryPow(long long int a, long long int b, long long int m){
	long long int ans = 1;
	while(b > 0){
		if(b & 1){
			ans =  ans * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}
int main(){
	long long int a, b, m;
	cin >> a >> b >> m;
	
	int result = binaryPow(a, b, m);
	printf("%d", result);
	return 0;
}
