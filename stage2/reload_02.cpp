// 左移运算符重载：可以输出用户自定义的数据类型

#include <iostream>
#include <ostream>
using namespace std;

class Person {
    friend ostream& operator<<(ostream &cout, Person &p);

    public:
    Person(int a, int b){
        m_A = a;
        m_B = b;
    }
private:

    // 利用成员函数重载，左移运算符   p.operator<<(cout)  简化版本 P << cout
    // 不会利用成员函数重载 << 运算符，因为无法实现 cout 在左侧
    // void operator<<(cout){

    // }
    int m_A;
    int m_B;
};

// 只能利用全局运算符重载左移运算符，本质 operator<< (cout, p) ，简化 cout << p 
ostream& operator<<(ostream &cout, Person &p){
    cout << "m_A = " << p.m_A << " " << "m_B = " << p.m_B << endl;
    return cout;
}
// 此处的 cout 为引用，为别名，可以修改为其他内容，如: out

void test01(){
    Person p(10, 10);
    // cout << p.m_A << endl;
    cout << p << endl;
}

int main() {
    test01();
    return 0;
}