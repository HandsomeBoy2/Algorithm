#include <iostream>
#include <string> 
#include <cctype> 
using namespace std;
int main()
{
	string a;      //输入 
	getline(cin, a);  
	int lena = a.length();
	for (int i = 0; i < lena; i++) {  //改成小写 
			a[i] = tolower(a[i]);
	}
	int count[26] = {0};  //用26个元素的一维数组统计存储 
	for (int i = 0; i < lena; i++) { 
		if (a[i] >= 'a' && a[i] <= 'z') {
			count[a[i]- 'a']++;
		}
	}
	int max = count[0];    
	int n = 0;
	for (int i = 1; i < 26; i++) {
		if (max < count[i]) {
			max = count[i];
			n = i;
		}
	}
	char temp = n + 'a';
	cout << temp << " " << max;
	return 0;
}

