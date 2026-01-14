// vector 存放自定义数据类型

#include<iostream>
#include<vector>

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


void test01(){
    vector<Person> v;
    
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // 遍历数据
    for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
        // cout << (*it).m_Name << " " << (*it).m_Age << endl;
        cout << it->m_Name << " " << it->m_Age << endl;
    }
}

// 存放自定义数据类型的指针
void test02(){
    vector<Person*> v;
    
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    
    // 遍历容器
    for (vector<Person*>::iterator it=v.begin(); it!=v.end(); it++){
        cout << (*it)->m_Name << " " << (*it)->m_Age << endl;
    }
}


int main(){
    // test01();
    test02();
    return 0;
}