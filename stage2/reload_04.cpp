// 赋值运算符重载

#include<iostream>
#include <ostream>
using namespace std;

class Person{
    public:
    Person(int age){
        m_Age = new int(age);
    }

    ~Person(){
        if (m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }

    // 重载 赋值运算符
    Person& operator=(Person &p){
        // 编译器是提供浅拷贝
        // m_Age = p.m_Age;

        // 应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }

        m_Age = new int(*p.m_Age);

        return *this;
    }

    int *m_Age;
};



void test01(){
    Person p1(100);

    Person p2(24);

    Person p3(39);

    p3 = p2 = p1; // 赋值操作

    cout << *p1.m_Age << endl;

    cout << *p2.m_Age << endl;

    

}

int main(){
    test01();
    return 0;
}