// 函数模板 和 类模板

// 函数模板：
// 建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表

// 语法：
// template<typename T>
// 函数声明或定义

// 解释：
// template -- 声明创建模板
// typename -- 表明其后面的符号是一种数据类型，可以用 class 代替
// T --- 通用的数据类型，名称可以替换，通常为大写字母

#include<iostream>

using namespace std;

// 两个整形交换
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点型的函数
void swapDouble(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}


// 函数模板
template <typename T> // 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}


void test01(){
    int a = 10;
    int b = 20;
    // swapInt(a, b);

    // 利用函数模板交换
    // 两种方式使用模板
    // 1、自动类型推倒
    // mySwap(a, b);

    // 2、显示指定类型
    mySwap<int>(a, b);

    cout << a << b << endl;

    // double c = 1.9;
    // double d = 3.9;
    // swapDouble(c, d);
    // cout << c << d << endl;
}

int main(){
    test01();
    return 0;
}