#include <cstdio>
#include <iostream>
using namespace std;

int htable[100001] = {0};

int main(){
	int N, M, temp;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> temp;
		htable[temp]++;
	} 
	for(int i = 0; i < M; i++){
		if(htable[i] >= 1 && htable[M-i] >= 1 && i < M-i){
			cout << i << " " << M-i;
			return 0;
		}	
		if(htable[i] >= 2 && i == M-i)	{
			cout << i << " " << i;
			return 0;
		}		
	}
	cout << "No Solution";
	return 0;
}
