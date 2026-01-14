// 类模板的基本用法

// template<typename T>
// 类

#include<iostream>

using namespace std;

// 类模板
template<class NameType, class AgeType>
class Person{
    public:

    Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << "Name : " << this->m_Name << "Age : " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};


void test01(){
    Person<string, int> p1("孙悟空", 99);
    p1.showPerson();
}

int main(){
    test01();
    return 0;
}