#include <iostream>
using namespace std;
int main() {
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;  //用A1-A5更简便 
    float A4 = 0.0;
    int N;
    cin >> N;
    int *a = new int [N];  //动态数组 
    int *b = new int [N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = 0;
    }
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0; //用于判断有没有对应值 
    int t = 0, count = 0;
    for (int i = 0; i < N; i++) {  //执行判断并修改flag的值 
        if (a[i] % 10 == 0) {
            A1 = A1 + a[i];
            flag1 = 1;
        }
        if (a[i] % 5 == 1) {
            b[t++] = a[i];
            flag2 = 1;
        }
        if (a[i] % 5 == 2) {
            A3++;
            flag3 = 1;
        }
        if (a[i] % 5 == 3) {
            A4 = A4 + a[i];
            count++;
            flag4 = 1;
        }
        if (a[i] % 5 == 4) {
            if (A5 < a[i]) {
                A5 = a[i];
                flag5 = 1;
            }
        }
    }
    for (int i = 0; i < t; i++) {   //交错求和 
        if (i == 0 || i % 2 == 0) {
            A2 = A2 + b[i];
        } else {
            A2 = A2 - b[i];
        }
    }
    A4 = A4 / count;   //平均值 
    if (flag1 == 0)  //输出结果 
        cout << "N ";
    else
        cout << A1 << " ";
    if (flag2 == 0)
        cout << "N ";
    else
        cout << A2 << " ";
    if (flag3 == 0)
        cout << "N ";
    else
        cout << A3 << " ";
    if (flag4 == 0)
        cout << "N ";
    else
        printf("%.1f ",A4);
    if (flag5 == 0)
        cout << "N";
    else
        cout << A5;
    delete [] a;  //释放内存 
    delete [] b;
    return 0;
}
