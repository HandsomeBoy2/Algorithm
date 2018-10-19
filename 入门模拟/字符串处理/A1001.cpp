#include <iostream>
#include <algorithm> 
#include <string>
using namespace std;
int main()
{
  string s;
  int a, b;
  cin >> a >> b;
  s = to_string(a + b);
  int len = s.length();
  for (int i = 0; i < len; i++) {
    cout << s[i];
    if (s[i] == '-') continue;
    if ((i + 1)  % 3 == len % 3 && i != len - 1) {
      cout << ",";
    }
  }
   return 0;
}
