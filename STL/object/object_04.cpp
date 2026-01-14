// 内建函数对象

// - 算术仿函数
// - 关系仿函数
// - 逻辑仿函数

// 引入头文件 #include<functional>

// 算术仿函数，实现四则运算
// negate 为一元运算，其他都是二元运算
// 仿函数原型
// - template<class T> T plus<T> // 加法仿函数
// - template<class T> T minus<T>
// - template<class T> T multiplies<T>
// - template<class T> T divides<T>
// - template<class T> T modulus<T> // 取模
// - template<class T> T nagate<T> // 取反仿函数


#include<iostream>
#include<functional>

using namespace std;

void test01(){
    negate<int> n;
    cout << n(10) << endl;
}


void test02(){
    plus<int> p;

    cout << p(10, 20) << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}