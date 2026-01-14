// 静态成员函数
#include<iostream>
using namespace std;

// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person{
public:
    static void func(){
        m_A = 200; // 静态成员函数可以访问 静态成员变量
        // m_B = 200; // 静态成员函数，不可以访问，非静态成员变量，因为无法区分到底是那个对象的 m_B 属性
        cout << "static void func 的调用" << endl;
    }

    static int m_A;
    int m_B; // 非静态成员变量

    // 静态成员函数也是有访问权限的
private:
    static void func2(){
        cout << "func" << endl;
    }
};

int Person :: m_A = 0; // 静态成员变量

//有两种访问方式
void test01(){
    // 通过对象进行访问
    Person p;
    p.func();
    // 通过类名进行访问
    Person :: func();
    // Person :: func2(); //类外访问不到私有静态成员函数
}

int main(){
    test01();
    return 0;
}