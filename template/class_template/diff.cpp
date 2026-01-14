// 类模板和函数模板的区别
// 区别主要有俩点
// 1、类模板没有自动类型推导的使用方式
// 2、类模板在模板参数列表中可以有默认参数

#include<iostream>

using namespace std;

template<class NameType, class AgeType = int>
class Person{
    public:

    Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << this->m_Name << " " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

// 1、
void test01(){
    // Person p1("章三", 99); // 错误，无法使用自动类型推导
    Person<string, int> p1("章三", 99);
    p1.showPerson();
}

// 2、
void test02(){
    // 可以 template<class NameType, class AgeType = int> 使用的时候就不用再写 int
    Person<string> p("猪八戒", 999);
    p.showPerson();
}


int main(){
    // test01();
    test02();
    return 0;
}