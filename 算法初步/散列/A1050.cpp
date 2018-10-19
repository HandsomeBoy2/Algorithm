#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define MAX 129

bool htable[MAX] = {false};
int main(){
	
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s1.length(); i++)
		htable[s1[i]] = true;
	for(int i = 0; i < s2.length(); i++)
		htable[s2[i]] = false;
	for(int i = 0; i < s1.length(); i++){
		if(htable[s1[i]]) 
			cout << s1[i];
	} 
		
	return 0;
} 
