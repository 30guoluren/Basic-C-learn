// 初始化列表
// C++ 提供了初始化列表语法，用来初始化属性
// 语法：构造函数(): 属性1(值1), 属性2(值2), 属性3(值3)... {}

#include <iostream>
using namespace std;

class Person{
public:

    // // 传统化操作
    // Person(int a, int b, int c){
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // 初始化列表初始化属性
    Person(int a, int b, int c):m_A(a),m_B(b),m_C(c){};

    int m_A;
    int m_B;
    int m_C;

};

void test01(){
    // Person p(10,20,30);
    Person p(10,25,23);
    cout << "A= " << p.m_A << "\t" << "B= " << p.m_B << "\t" << "C= " << p.m_C << endl;
}

int main() {
    test01();
    return 0;
}