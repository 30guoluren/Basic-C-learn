#include <iostream>
using namespace std;

// 1、new 的基本语法
int* func() {
    // 在堆区创建一个整型的数据
    // new 返回的是该数据类型的一个指针
    int* p = new int(10);
    return p;
}

void test_01() {
    int* p = func();
    cout << *p << endl;
    // 堆区的数据由程序员管理和释放
    // 释放时使用 delete 来进行释放
    delete p;
    cout << *p << endl;
}

// 2、在堆区利用 new 开辟数组
void test_02() {
    // 创建一个 10 整型的数组，在堆区
    int* arr = new int[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 100;  // 给十个元素赋值
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }

    // 释放堆区数组
    // 释放堆区数组的时候，要加一个 [] 才可以
    delete[] arr;
}

int main() {
    // test_01();
    test_02();
    return 0;
}