// C++ 对象模型和 this 指针

// 成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上

#include<iostream>
using namespace std;

class Person{
    int m_A; // 非静态成员变量，属于类的对象上

    static int m_B; // 静态成员变量，不属于类的对象上

    void func(){} // 非静态成员函数，不属于类的对象

    static void func2(){} // 静态成员函数，不属于类的对象上1

};

int Person :: m_B = 0;

void test01(){
    Person p;
    // 空对象占用内存为：1
    // C++ 编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "size of " << sizeof(p) << endl;
}

void test02(){
    Person p;
    // 空对象占用内存为：4
    cout << "size of " << sizeof(p) << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}