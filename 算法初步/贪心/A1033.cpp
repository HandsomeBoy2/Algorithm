#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station {
	double price;
	double dis;
}stations[maxn];
int cmp(struct station a, struct station b) {
	return a.dis < b.dis;
}
int main() {
	int n;
	double cmax, d, davg; 
	cin >> cmax >> d >> davg >> n;
	for(int i = 0; i < n; i++) {
		cin >> stations[i].price >> stations[i].dis;
	}
	stations[n].price = 0;
	stations[n].dis = d;
	sort(stations, stations+n, cmp);

	if(stations[0].dis > 0) {
		cout << "The maximum travel distance = 0.00";
	} else{
		int now = 0;
		double cost = 0.0, nowTank = 0, longest = cmax * davg;
		
		while(now < n){
			int k = -1;
			double priceMin = INF;
			for(int i = now+1; i <= n&&stations[i].dis-stations[now].dis<=longest; i++){
				if(stations[i].price < priceMin){
					priceMin = stations[i].price;
					k = i;
					if(priceMin < stations[now].price)
						break;
				}
			}
			if(k == -1) break;
			double need = (stations[k].dis - stations[now].dis) / davg;
			if(priceMin < stations[now].price){
				if(nowTank < need){
					cost += (need-nowTank) * stations[now].price;
					nowTank = 0;
				}else{
					nowTank -= need;
				}
			}else {
				cost += (cmax-nowTank) * stations[now].price;
				nowTank = cmax-need;
			}	
			now = k;	
		}
		if(now == n){
			printf("%.2f\n", cost);
		}else{
			printf("The maximum travel distance = %.2f\n", stations[now].dis+longest);
		}	
	}
	return 0;
}

