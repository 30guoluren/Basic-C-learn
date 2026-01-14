// 类模板分文件编写

#include<iostream>

// 第一种解决方法直接包含源文件
// #include "person.cpp"

// 第二种，将 .h 和 .cpp 文件写到一起，将后缀名改为 .hpp 文件
#include "person.hpp"

using namespace std;

// template<class T1, class T2>
// class Person{
//     public:

//     Person(T1 name, T2 age);


//     void showPerson();

//     T1 m_Name;
//     T2 m_Age;
// };


// template<class T1, class T2>    // Person<string, int> p("李", 27);
    // p.showPerson();
// Person<T1, T2> :: Person(T1 name, T2 age){
//     this->m_Name = name;
//     this->m_Age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2> :: showPerson(){
//     cout << this->m_Name << endl;
//     cout << this->m_Age << endl;
// }


void test01(){
    Person<string, int> p("李", 27);
    p.showPerson();
}



int main(){
    test01();
    return 0;
}