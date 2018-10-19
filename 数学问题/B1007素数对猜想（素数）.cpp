#include <iostream>
using namespace std;

bool isprime(int a) {//素数返回true，反之false
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i++) {//测试素数对 
        if (isprime(i-2) && isprime(i))
            cnt++;
    }
    cout << cnt;
    return 0;
}
