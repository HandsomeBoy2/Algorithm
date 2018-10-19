#include <iostream>
#include <vector>
#include <algorithm>
struct mooncake 
{
	float weight;
	float price;
	double unit;
};
bool cmp(mooncake a, mooncake b) { return a.unit > b.unit;}
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector <mooncake> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].weight;
	for (int i = 0; i < n; i++)
		cin >> a[i].price;
	for (int i = 0; i < n; i++) 
		a[i].unit = a[i].price / a[i].weight;
	sort(a.begin(), a.end(), cmp);
	float result = 0.0;
	for (int i = 0; i < n; i++) {
		if (a[i].weight <= m) {
			result = result + a[i].price;
		} else {
			result = result + a[i].unit * m;
			break;
		}
		m = m - a[i].weight;
	}
	printf("%.2f", result);
	return 0;
}

