// 排序案例
#include <cstdio>
#include<iostream>
#include<list>

using namespace std;

class Person{
    public:

    Person(string name, int age, int height){
        this->m_Height = height;
        this->m_Age = age;
        this->m_Name = name;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

bool comparePerson(Person &p1, Person &p2){
    // 年龄升序，年龄相同;按升高降序
    if (p1.m_Age == p2.m_Age){
        return p1.m_Height > p2.m_Height;
    }
    else {
        return p1.m_Age < p2.m_Age;
    }
}


void printList(const list<Person> &l){
    for (list<Person>::const_iterator it=l.begin(); it!=l.end(); it++){
        cout << (*it).m_Name << " " << (*it).m_Age << " " << it->m_Height << endl;
    }
}


void test01(){
    list<Person> l;
    Person p1("a", 12, 170);
    Person p2("b", 15, 172);
    Person p3("c", 3, 123);
    Person p4("d", 15, 170);
    Person p5("e", 15, 178);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);

    // printList(l);

    cout << "00-----------00" << endl;
    l.sort(comparePerson);
    printList(l);

}

int main(){
    test01();
    return 0;
}