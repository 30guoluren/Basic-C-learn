// 构造函数的调用规则

#include<iostream>
using namespace std;

// 构造函数的调用规则
// 1、创建一个类，C++ 编译器会给每个类添加至少三个函数
// 默认构造 （空实现）
// 析构构造 （空实现）
// 拷贝构造 （值拷贝）

// 2、如果我们写了有参构造函数，编译器就不再提供默认构造，依旧提供拷贝构造
// 如果我们写了拷贝构造函数，编译器就不提供默认构造，有参构造。

class Person{
public:
    Person(){
        cout << "Person 的默认构造函数调用" << endl;
    }

    Person(int age){
        m_Age = age;
        cout << "Person 的有参构造函数调用" << endl;
    }

    // Person(const Person &p){
    //     m_Age = p.m_Age;
    //     cout << "Person 的拷贝构造函数调用" << endl;
    // }

    ~Person(){
        cout << "Person 的析构构造函数调用" << endl;
        
    }

    int m_Age;
};

void test01(){
    Person p;
    p.m_Age = 18;
    // Person p(18);

    Person p2(p);
    cout << "p2 的年龄为：" << p2.m_Age << endl;
}

void test02(){
    Person p(19);
}

int main(){
    // test01();
    test02();
    return 0;
}