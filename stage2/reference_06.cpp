// 常量引用：修饰形参，防止误操作

#include<iostream>
using namespace std;

void showValue(const int& val){
    // val = 1000;
    cout << "val: " << val << endl;
}

int main(){

    int a = 10;
    int & ref = a;
    // int & ref = 10; // 非法，10 为常量，未在内存中开辟空间，而引用必须引一块合法的内存空间
    // 但
    const int & ref1 = 10; // 加上 const 后，编译器将代码修改为：int temp = 10; int & ref2 = temp;
    // ref1 = 200; // 加入 const 变为只读，不能再修改

    int b = 100;
    showValue(b);

    cout << "b = " << b << endl;
    return 0;
}