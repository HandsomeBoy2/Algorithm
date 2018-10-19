#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  	int M, N, A, B, G;
  	cin >> M >> N >> A >> B >> G;
  	int a[M][N];
  	for (int i = 0; i < M; i++) {
    	for (int j = 0; j < N; j++) {
      		cin >> a[i][j];
      		if (a[i][j] >= A && a[i][j] <= B) {
        	a[i][j] = G;
      	}
    	}
  	}
  	for (int i = 0; i < M; i++) {
    	for (int j = 0; j < N; j++) {
      		if (j != 0) cout << " ";
      		printf("%03d", a[i][j]);
    	}
    	cout << endl;
  	}
  
  	return 0;
}
