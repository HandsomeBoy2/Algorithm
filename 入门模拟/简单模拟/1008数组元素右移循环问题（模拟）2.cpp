#include <iostream> 
#include <vector> 
using namespace std;
int main()
{
	int n, m;
	cin >> n >>  m;
	vector <int> a(n);  //动态数组 
	if(m > n)  //若移动位数多于数组元素个数 
		m = m - n;
	for (int i = 0; i < n; i++)
        cin >> a[i];
	int *b = new int[m]; //存储m个元素 
	int j = m;
	for (int i = n-1; i >= 0; i--) {  //将数组后面m个元素放在b中 
		if (i >= n-m) {
			b[--j] = a[i];
		} else {  //将0 - m-1个元素后移m位 
			a[i+m] = a[i];
		}
	}
	for (int i = 0; i < m; i++) { //将m个元素添加到a中 
		a[i] = b[i];
	}
	for (int i = 0; i < n - 1; i++) 
			cout << a[i] << " ";
	cout << a[n-1];
	delete [] b;
	return 0;
}
