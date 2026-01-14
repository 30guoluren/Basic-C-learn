#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b);
    cout << "c = " << c << endl;

    // 在 C++ 中，三目运算符返回的是一个变量，可以继续进行赋值。
    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}