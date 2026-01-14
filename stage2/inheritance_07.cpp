// 多继承语法
// C++ 允许一个类继承多个类

// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2...

// 多继承可能会引发父类中有同名成员出现，需要加作用域以区分

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base1{
    public:
    int m_A;

    Base1(){
        m_A = 100;
    }

};

class Base2{
    public:
    int m_A;
    Base2(){
        m_A = 200;
    }
};

class Son : public Base1, public Base2{
    public:
    Son(){
        m_C = 399;
        m_D = 499;
    }

    int m_C;
    int m_D;
};

void test01(){
    Son s;
    cout << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}