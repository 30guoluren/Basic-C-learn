// 静态成员
// 静态成员就是在成员变量和成员函数之前加上 static，称为静态成员

// 静态成员分为：
// 静态成员变量
// - 所有对象共享同一份数据
// - 在编译阶段分配内存
// - 类内声明，类外初始化

// 静态成员函数
// - 所有对象共享同一个函数
// - 静态成员函数只能访问静态成员变量

#include<iostream>
using namespace std;

class Person{
public:
    // 所有对象都共享同一份数据
    // 在编译阶段就分配内存
    // 类内声明，类外初始化
    static int m_A;

    // 静态成员变量也是有访问权限的
private:
    static int m_B;
};

int Person :: m_A = 100;
int Person :: m_B = 200;

void test01(){
    Person p;
    cout << p.m_A << endl;

    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}

void test02(){
    // 静态成员变量，不属于某个对象，所有对象都共享同一份数据
    // 因此静态成员变量有两种访问方式

    // 1、通过对象进行访问
    Person p;
    cout << p.m_A << endl;

    // 2、通过类名进行访问
    cout << Person :: m_A << endl;
    // cout << Person :: m_B << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}