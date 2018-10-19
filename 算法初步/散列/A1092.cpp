#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int htable[129] = {0};

int main(){
	string s, s1;

	getline(cin, s);
	getline(cin, s1);
	
	int cnt = 0;
	
	for(int i = 0; i < s.length(); i++){
		htable[s[i]]++;
	}
	for(int i = 0; i < s1.length(); i++){
		if(htable[s1[i]] > 0){
			htable[s1[i]]--;
		} else {
			cnt++;
		}	
	}
	if(cnt > 0){
		cout << "No " << cnt;
	} else {
		cout << "Yes " << s.length()-s1.length();
	}
	
	return 0;
}
