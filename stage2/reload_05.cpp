// 关系运算符重载：重载关系运算符，可以让两个自定义类型对象进行对比操作

#include<iostream>
using namespace std;

class Person{
    public:
    Person(string name, int age){
        m_Name = name;
        m_Age = age;
    }

    // 重载 == 号
    bool operator==(Person &p){
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        }
        return false;
    }

    string m_Name;
    int m_Age;
};

void test01(){
    Person p1("lili", 19);
    Person p2("lili", 19);

    if (p1 == p2){
        cout << "p1 == p2" << endl;
    }
    else{
        cout << "p1 != p2" << endl;
    }
}

int main(){
    test01();
    return 0;
}