/*
递增序列中有重复元素，查询出其所在区间 
*/
#include <cstdio>
#include <iostream>
using namespace std;
int lower_bound(int a[], int left, int right, int target){
	
	int mid;
	while(left < right){
		mid = left + (right - left) / 2; //可以防止溢出 
										
		if(a[mid] >= target) 
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int upper_bound(int a[], int left, int right, int target){
	int mid;
	while(left < right){
		mid = left + (right - left) / 2; //可以防止溢出 
										
		if(a[mid] > target) 
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}


int main(){
	const int n = 10;
	int a[n] = {1, 5, 8, 9, 9, 9, 9, 22, 25, 35};
	
	int index1 = lower_bound(a, 0, n-1, 9);
	int index2 = upper_bound(a, 0, n-1, 9); 
	
	printf("%d-%d", index1, index2);
	
	return 0;
}
