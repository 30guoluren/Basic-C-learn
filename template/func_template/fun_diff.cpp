// 普通函数与函数模板的区别
// 普通函数调用的时候，可以发生自动类型转换（隐式类型转换）
// 函数模板调用时，如果利用自动类型推倒，不会发生隐式类型转换
// 如果利用显示指定类型的方式，可以发生隐式类型转换

#include<iostream>

using namespace std;

int myAdd01(int a, int b){
    return a + b;
}

// 模板
template<class T>
T myAdd02(T a, T b){
    return a + b;
}


void test01(){
    int a = 20;
    int b = 30;

    char c = 'c'; // 将字符 c 转换为 ascii 码，整型.
    cout << myAdd01(a, c) << endl;

    // cout << myAdd02(a, c) << endl; // 不会发生隐式类型转换
    cout << myAdd02<int>(a, c) << endl; 
}


int main(){
    test01();
    return 0;
}