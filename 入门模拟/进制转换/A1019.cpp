#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int num[5000];
int main(){
	int N, b, i = 0;
	cin >> N >> b;
	while(N!= 0){
		num[i++] = N % b;
		N /= b;
	}
	int flag = 0;
	for(int j = 0; j < i/2; j++){
		if(num[j] != num[i-1-j]){
			cout << "No" << endl;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		cout << "Yes" << endl; 
	for(int j = i-1; j > 0; j--)
		cout << num[j] << " ";
	cout << num[0];
	return 0;
}

