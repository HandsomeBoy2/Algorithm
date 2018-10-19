#include <cstdio> 
#include <iostream>
#include <algorithm>
using namespace std;
int N, K;

void solve(int left, int right, int a[]){
 	int mid, sum; 
	while(left+1 < right){
		mid = (left+right) / 2;
		sum = 0;
		for(int i = 0; i < N; i++)
			sum += a[i] / mid;
		if(sum < K)
			right = mid;
		else
			left = mid;
	}
	printf("%d", left);
}

int main(){
	cin >> N >> K;
	int a[N];
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	sort(a, a+N);	
	solve(0, a[N-1], a);	
	return 0;
}
