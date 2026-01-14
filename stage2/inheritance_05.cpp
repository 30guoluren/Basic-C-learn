// 继承同名成员处理方式
// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据
// - 访问子类同名成员，直接访问即可
// - 访问父类同名成员，需要加作用域

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base{
    public:

    void func(){
        cout << "Base 的 func 函数调用" << endl;
    }

    void func(int a){
        cout << "Base 的 func(int a) 函数调用" << endl;
    }

    Base(){
        m_A = 100;
    }

    int m_A;

};

class Son: public Base{
    public:

    void func(){
        cout << "Son 下的 func 调用" << endl;
    }


    Son(){
        m_A = 200;
    }
    int m_A;
};

void test01(){
    Son s;
    cout << s.m_A << endl;
    cout << "Base 下 m_A = " << s.Base :: m_A << endl;
}


void test02(){
    Son s;
    s.func();
    s.Base :: func();

    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    // 如果想访问到父类中被隐藏的同名成员函数，，需要加作用域
    s.Base :: func(10);
}


int main(){
    system("chcp 65001");
    // test01();
    test02();
    return 0;
}