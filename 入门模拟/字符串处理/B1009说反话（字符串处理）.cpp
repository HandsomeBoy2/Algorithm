#include <iostream>  
#include <string>  
#include <sstream>   //头文件中包含istringstream
#include <stack>  
using namespace std;  
string str;  
stack<string> s;  //栈中存储string
int main() {  
    while(getline(cin,str)) { //输入字符串       
        istringstream it(str);  //字符串扫描流
        bool isfirst = true;  
        while ( it >> str ) {  //开始扫描 遇到空格就停止扫描
            s.push(str);  //压入栈
        }  
        while (!s.empty()) {  
            if (isfirst) {  
                isfirst = false;  
                cout<<s.top();  //输出栈顶元素
            }  
            else {  
                cout<<" "<<s.top();  
            }  
            s.pop();  //弹出栈顶元素
        }  
        cout<< endl;  
    }  
  
    return 0;  
}  
