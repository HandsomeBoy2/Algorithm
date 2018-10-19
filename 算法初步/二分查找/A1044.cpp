#include <cstdio>
#include <iostream>
using namespace std;
int upper_bound(int left, int right, int x, int d[]){
	int mid;
	while(left < right){
		mid = (left+right) / 2;
		if(d[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}
int main(){
	int N, M, nearM = 1000010;
	cin >> N >> M;
	int d[N+1];
	d[0] = 0;
	for(int i = 1; i <= N; i++){
		cin >> d[i];
		d[i] += d[i-1];
	}
	for(int i = 1; i <= N; i++){
		int j = upper_bound(i, N+1, d[i-1]+M, d);
		if(d[j-1] - d[i-1] == M){
			nearM = M;
			break;
		}else if(j <= N && d[j] - d[i-1] < nearM){
			nearM = d[j] - d[i-1];
		}
	}	
	
	for(int i = 1; i <= N; i++){
		int j = upper_bound(i, N+1, d[i-1]+nearM, d);
		if(d[j-1] - d[i-1] == nearM){
			printf("%d-%d\n", i, j-1);
		}
	}
	return 0;
}

