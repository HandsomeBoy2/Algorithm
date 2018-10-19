#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int n = ((b - a) + 50) / 100; //四舍五入 所以要考虑加点东东
								  //例如 110或180代入就可以满足四舍五入的条件了 
    int hour = n / 3600;
    n = n % 3600;
    int minute = n / 60, second = n % 60;
    printf("%02d:%02d:%02d", hour, minute, second);
    return 0;
}
