#include <iostream>  
#include <string>  
using namespace std;  
bool func(string s);  //定义bool型func函数  
int main()   
{  
    int n;  
    cin >> n;   
    int count = 0;//计算器  用来检查是否有问题  
    for (int i = 0; i < n; i++)   
    {  
        string a;  
        cin >> a;  
        if(func(a))   //调用函数  
            ++count;  
    }  
    if (count == 0)  
        cout << "All passed";  
    return 0;  
}  
  
bool func(string s)   
{  
    int sum = 0;  
    int a[18]; //用来存储字符串中字符 将其转换成数字  
    for (int i = 0; i < 17; i++)   
    {  
        if (!isdigit(s[i]))   
        {  
            cout << s << endl;  
            return true;  
        }  
        a[i] = s[i] - '0';  
    }  
    if (s[17] == 'X')  //若第18为X，则改成10  
        a[17] = 10;  
    else  
        a[17] = s[17] - '0';  
    int b[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; //加权求和  
    for (int i = 0; i < 17; i++)  
    {  
        sum = sum + a[i] * b[i];  
    }  
    sum = sum % 11; //算出校验码的位置  
    int c[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};  
    if (c[sum] != a[17])  //校验  
    {  
        for (int i = 0; i < 17; i++)  
            cout << s[i];  
        if (a[17] == 10)  
            cout << "X" << endl;  
        else  
        {  
            cout << a[17] << endl;  
        }     
        return true;  
    }  
    else   
    {  
        return false;  
    }     
}  
