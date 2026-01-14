#include<iostream>
using namespace std;

int main(){
    // 引用必须初始化
    int a = 0;
    // int &b; // 此处必须初始化
    int &b = a;
    // 初始化之后，就不能再改变
    int c = 20;

    b = c; // 此处为赋值操作，而不是更改引用
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;


    return 0;
}