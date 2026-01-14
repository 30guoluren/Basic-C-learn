// set 存放自定义数据类型进行排序

#include <functional>
#include<iostream>
#include<set>

using namespace std;

class Person{
    public:

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class MyComaperPerson{
    public:
    bool operator()(const Person &p1, const Person &p2){
        // 按照；年龄降序
        return p1.m_Age > p2.m_Age;
    }
};

void test01(){
    // 自定义的数据类型都会指定排序规则
    set<Person, MyComaperPerson> s;
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, MyComaperPerson>::iterator it=s.begin(); it!=s.end(); it++){
        cout << (*it).m_Name << (*it).m_Age << endl;
    }
}

int main(){
    test01();
    return 0;
}