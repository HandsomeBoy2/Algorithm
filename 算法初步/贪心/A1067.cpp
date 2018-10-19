#include <cstdio> 
#include <algorithm>
using namespace std;
int a[100010];
int main(){
	int n;
	scanf("%d", &n);
	int num, left = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		a[num] = i;
		if(num != i && i > 0)
			left++;
	}
	int ans = 0, k = 1;
	while(left > 0){
		if(a[0] == 0){
			while(k < n){
				if(a[k] != k){
					swap(a[0], a[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(a[0] != 0){
			swap(a[0], a[a[0]]);
			ans++;
			left--;
		}	
	}
	printf("%d", ans);
	return 0;
}
