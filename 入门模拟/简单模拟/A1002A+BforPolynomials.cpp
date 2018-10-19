#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int n, N, cnt = 0;
	double aN = 0.0f;
	map<int, double>p;
	for (int i = 1; i <= 2; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d%lf", &N, &aN);
			p[N] += aN; 
		}
	}
	for(auto a = p.begin(); a!= p.end(); a++) {
		if(a->second != 0.0 && a->second != -0.0)
			cnt++;
	}
	printf("%d", cnt);
	for (auto a = p.rbegin(); a != p.rend(); a++) {
		if(a->second != 0.0 && a->second != -0.0)
			printf(" %d %.1lf", a->first, a->second); 
	}
 	return 0;
}

