// 类对象作为类成员
// C++ 类中的成员可以是另一个类的对象，我们称该成员为：成员对象

#include<iostream>
using namespace std;

class Phone{
public:
    Phone(string pName){
        m_PName = pName;
        cout << "Phone 的构造函数调用" << endl;
    }

    ~Phone(){
        cout << "Phone 的析构函数调用" << endl;
    }

    string m_PName;

};

class Person{
public:

    // Phone m_Phone = pName; 隐式转换发
    Person(string name, string pName):m_Name(name),m_Phone(pName){
        cout << "Person 的构造函数调用" << endl;
    }

    ~Person(){
        cout << "Person 的析构函数调用" << endl;
    }

    string m_Name;
    Phone m_Phone;
};


// 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构的构造顺序相反
void test01(){
    Person p("张三", "iphone");
    cout << p.m_Name << p.m_Phone.m_PName << endl;
}

int main(){
    test01();
    return 0;
}

