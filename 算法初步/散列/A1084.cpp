#include <cstdio>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool htable[129];

int main(){
	string s, s1;
	getline(cin, s);
	getline(cin, s1);
	
	for(int i = 0; i < s.length(); i++){
		if(isalpha(s[i]))
			s[i] = toupper(s[i]);
		htable[s[i]] = true;
	}
	for(int i = 0; i < s1.length(); i++){
		if(isalpha(s1[i]))
			s1[i] = toupper(s1[i]);
		htable[s1[i]] = false;
	}
	for(int i = 0; i < s.length(); i++){
		if(htable[s[i]]){
			cout << s[i];
			htable[s[i]] = false;
		}
	}
	
	return 0;
}
