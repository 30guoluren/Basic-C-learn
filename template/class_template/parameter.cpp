// 类模板对象做函数参数
// 类模板实例化出的对象，向函数传参的方式

// 一共 3 种
// 1、指定传入的类型 -- 直接显示对象的数据类型
// 2、参数模板化    -- 将对象中的参数变为模板进行传递
// 3、整个类模板化   -- 将这个对象类型 模板化进行传递

#include<iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person{
    public:

    Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << this->m_Name << endl;
        cout << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};


// 1、
void printPerson1(Person<string, int>&p){
    p.showPerson();
}

void test01(){
    Person<string, int> p("孙", 100);
    printPerson1(p);
}


// 2、
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p){
    p.showPerson();
    cout << "T1 的类型为: " << typeid(T1).name() << endl;
    cout << "T2 的类型为: " << typeid(T2).name() << endl;

}


void test02(){
    Person<string, int> p("dog", 100);
    printPerson2(p);
}


// 3、
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout << "T 的数据类型为: " << typeid(T).name() << endl;
}

void test03(){
    Person<string, int> p("唐", 199);
    printPerson3(p);
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}