#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a, int b){
	return a > b;
}
int main(){
	int nc, nf;
	scanf("%d", &nc);
	int a[nc];
	for(int i = 0; i < nc; i++)
		scanf("%d", &a[i]);
	sort(a, a+nc, cmp);	
		
	scanf("%d", &nf);
	int b[nf];
	for(int i = 0; i < nf; i++)
		scanf("%d", &b[i]);
	sort(b, b+nf, cmp);
	
	int i=0, ans=0;
	while(i < nc && i < nf && a[i] > 0 && b[i] > 0){
		ans += a[i]*b[i];
		i++;
	}
	int j = nc-1, j1 = nf-1;
	while(j >= 0 & j1 >= 0 && a[j] < 0 && b[j1] < 0){
		ans += a[j] * b[j1];
		j--;
		j1--;
	}
	cout << ans;
	return 0;
}

