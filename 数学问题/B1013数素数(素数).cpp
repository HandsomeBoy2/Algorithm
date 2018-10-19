#include <iostream>

bool isprime(int a)  //判断是否为素数 
{
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) 
			return false;
	}
	return true;
}
using namespace std;
int main()
{
	int M = 0, N = 0;
	int t = 0, k = 2;
	int a[10000];
	int j = 0;
	cin >> M >> N;
	while (t < N) {     //存储第N-M个之间的素数在a数组中 
		if (isprime(k)) {
			t++;
			if (t >= M) 
				a[j++] = k;
		}
		k++;	
	}
	for (int i = 0; i < j; i++) {  //输出 
		cout << a[i];
		if ((i + 1) % 10 == 0)  //后接空格或换行 最后一个素数后不接任何东西 
         	cout << endl;
        else if (i != j-1)  
        	cout << " "; 
	}
	return 0;
}

