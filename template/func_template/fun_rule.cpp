// 普通函数与函数模板的调用规则
// 1、如果函数模板和普通函数都可以实现，优先调用普通函数
// 2、可以通过空模板参数列表来强制调用函数模板
// 3、函数模板可以发生重载
// 4、如果函数模板可以产生更好的匹配，优先调用函数模板

#include<iostream>

using namespace std;

void myPrint(int a, int b)
{
    cout << "调用普通函数" << endl;
}

template<class T>
void myPrint(T a, T b){
    cout << "这是函数模板的调用" << endl;
}

template<class T>
void myPrint(T a, T b, T c){
    cout << "这是函数 重载 模板的调用" << endl;
}

void test01(){
    int a = 10;
    int b = 10;

    myPrint(a, b);

    // 通过空函数参数列表，强制调用函数模板
    myPrint<>(a, b);

    // 重载
    myPrint(a, b, 10);

    // 如果函数模板产生更好的匹配，优先调用函数模板
    char c1 = 'c';
    char c2 = 'b';
    myPrint(c1, c2);
}


int main(){
    test01();
    return 0;
}