#include <iostream>  
#include <string>  
using namespace std;  
int main()  
{  
    string s;  
    cin >> s;  
    if (s[0] == '-')  //负数则输出负号  
        cout << "-";  
    int pos = 0, after = 0, len = s.length();  
    for (int i = 1; i < len; i++) { //找出E的位置  
        if (s[i] == 'E')  
            pos = i;  
    }  
    for (int i = pos+2; i < len; i++) { //计算出E后数字的大小  
        after = (s[i] - '0') + 10 * after;  
    }  
    if(s[pos+1] == '-') { //E后为负号时  
        if (0 < after) {//且after为正数时 缩小数字  
            cout << "0.";  
            for (int i = 1; i < after; i++) {  
                cout << 0;  
            }     
            for (int i = 1; i < pos; i++) {  
                if (s[i] >= '0' && s[i] <= '9') {  
                    cout << s[i];  
                }     
            }  
              
        } else { //after为0时，原样输出  
            for (int i = 1; i < pos; i++) {  
                if (i == 2 - after) {  
                    cout << ".";  
                }     
                if (s[i] >= '0' && s[i] <= '9') {  
                    cout << s[i];  
                }  
            }     
        }     
    }   
    else { //E后为正号时  
        if (pos - 3 < after) { //判断  扩大数字在后面加0  
            if (s[1] != '0')  
                cout << s[1];  
            for(int i = 3; i < pos; i++) {  
                if (s[i] >= '0' && s[i] <= '9') {  
                    cout << s[i];  
                }  
            }  
            for (int i = 0; i < after - (pos - 3); i++) {  
                cout << 0;  
            }  
        } else { //判断  未扩大数字 将小数点后移  
            if(s[1] != '0')  
                cout << s[1];  
            for (int i = 3; i < pos; i++) {  
                if (i == 3 + after) {  
                    cout << ".";  
                }  
                if (s[i] >= '0' && s[i] <= '9') {  
                    cout << s[i];   
                }   
            }  
        }     
    }  
    return 0;     
}  
