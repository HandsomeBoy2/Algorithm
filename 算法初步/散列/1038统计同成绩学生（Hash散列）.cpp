#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m, temp;
    cin >> n;
    vector<int> a(n), b(101);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (i != 0) cout << " ";
        cout << b[temp];
    }
	
	return 0;
}

