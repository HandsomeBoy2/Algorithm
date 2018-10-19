#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d; //输入四个字符串
    int lena = a.length(); //测量字符串长度
    int lenb = b.length();
    int min1 = lena < lenb ? lena : lenb; //a，b相比，存储字符串较短的字符数
    int lenc = c.length(); //测量字符串长度
    int lend = d.length();
    int min2 = lenc < lend ? lenc : lend; //c，d相比，存储字符串较短的字符数
    char t[2];  //用来存储字符串中相同的字符
    int pos;
    int j;
    for (int i = 0; i < min1; i++) {  //找出第一个相同的字符并用j标记
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            a[i] = '#';
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < min1; i++) { //找出第二个相同的字符
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') ||
                             (a[i] >= '0' && a[i] <= '9'))) {
            t[1] = a[i];
            break;
        }
    }
    for (int i = 0; i < min2; i++) { //找出第三个相同的字符位置
        if (c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))) {
            pos = i;
            break;
        }
    }
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m;
    if (t[1] >= '0' && t[1] <= '9') { //将字符转换成数字
        m = t[1] - '0';
    } else {
        m = t[1] - 'A' + 10;
    }
    cout << week[t[0]-'A']; //输出
    if (m >= 0 && m <= 9) {
        cout << 0 << m << ":";
    } else {
        cout << m << ":";
    }
    if (pos >= 0 && pos <= 9) {
        cout << 0 << pos;
    } else {
        cout << pos;
    }
    return 0;
}
