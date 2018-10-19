#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(string a, string b){
	return a+b < b+a;
}
int main(){	
	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s+n, cmp);
	string ans;
	for(int i = 0; i < n; i++){
		ans += s[i];
	}
	while(ans.size() != 0 && ans[0] == '0'){
		ans.erase(ans.begin());
	}
	if(ans.size() == 0)
		cout << 0;
	else
		cout << ans;
	return 0;
}

