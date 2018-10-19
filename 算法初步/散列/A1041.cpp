#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 10001

int htable[MAX] = {0};
int main(){
	int N;
	cin >> N;
	int temp[N];
	for(int i = 0; i < N; i++){
		cin >> temp[i];
		htable[temp[i]]++;
	} 
	for(int i = 0; i < N; i++){
		if(htable[temp[i]] == 1){
			cout << temp[i];
			return 0;
		}
	}
	cout << "None";
	
	return 0;
} 
