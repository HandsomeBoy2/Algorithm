#include <iostream> 
#include <cctype> 
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	char c[80]; //存储坏的键盘字母 
	int flag, index = 0; 
	for (int i = 0; i < a.length(); i++) { //对比  用flag控制跳出循环或存储 
		flag = 0;
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				flag = 1;
				break;
			}
		}
		if (!flag) c[index++] = toupper(a[i]);
	}
	for (int i = 1; i < index; i++) { //将c中相同字母用‘#’代替 
		for (int j = 0; j < i; j++) {
			if (c[i] == c[j]) {
				c[i] = '#';
				break;	
			}	
		}
	}
	for (int i = 0; i < index; i++) { //输出坏的键盘字母 
		if (c[i] != '#') 
			cout << c[i];
	}
	return 0;
}
