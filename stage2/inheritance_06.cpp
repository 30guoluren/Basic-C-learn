// 继承中同名的静态成员处理方式
// 问题：继承中同名的静态成员在子类对象上如何进行访问

// 静态成员和非静态成员出现同名，处理方式一致
// - 访问子类同名成员，直接访问即可
// - 访问父类同名成员，需要加作用域

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base{
public:
    static int m_A;

    static void func(){
        cout << "Base static void func()" << endl;
    }

};
int Base :: m_A = 10;

class Son: public Base{
    public:
    static int m_A;

    static void func(){
        cout << "Son static void func()" << endl;
    }
};
int Son :: m_A = 299;

// 同名静态成员属性
void test01(){
    // 静态成员变量的访问方式
    // 1、通过对象访问
    Son s;
    cout << "Son 下的 m_A: "<< s.m_A << endl;
    cout << "Base 下的 m_A: " << s.Base :: m_A << endl;

    // 2、通过 类名 进行访问
    cout << "通过类名进行访问" << endl;
    cout << "Son 下的 m_A: " << Son :: m_A << endl;
    // 第一个 :: 代表通过类名的方式进行访问；第二个 :: 代表访问父类作用域下
    cout << "Base 下的 m_A: " << Son :: Base :: m_A << endl;

}

// 同名静态成员函数
void test02(){
    // 通过对象进行访问
    Son s;
    s.func();
    s.Base :: func();

    // 通过类名进行访问
    cout << "通过类名的方式进行访问" << endl;
    Son ::func();
    Son :: Base ::func();
}

int main(){
    system("chcp 65001");
    // test01();
    test02();
    return 0;
}