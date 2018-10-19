#include <cstdio>
using namespace std;
int main() {
    int a, b;
    bool flag = true;
    while(scanf("%d %d", &a, &b) != EOF) {  //输入 
        if(b == 0) continue; //检验指数是否为0 
        if(!flag) 
            printf(" ");
        else
            flag = false;
        printf("%d %d", a * b, b - 1);//输出 
    }
    if(flag) {
        printf("0 0");
    }
    return 0;
}

