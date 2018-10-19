/*
递增序列的二分查找 
*/
#include <cstdio>
#include <iostream>
using namespace std;
int binary_search(int a[], int left, int right, int target){
	
	int mid;
	while(left <= right){
		mid = (left + right) / 2;
		if(a[mid] == target) return mid;
		if(a[mid] > target) 
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main(){
	const int n = 10;
	int a[n] = {1, 5, 8, 9, 10, 15, 21, 22, 25, 35};
	
	int index1 = binary_search(a, 0, n-1, 9);
	int index2 = binary_search(a, 0, n-1, 23);
	
	printf("%d, %d", index1, index2);
	
	return 0;
}
